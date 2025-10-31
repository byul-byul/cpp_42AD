/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 09:46:57 by bh                #+#    #+#             */
/*   Updated: 2025-10-31 09:46:57 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp (ex03)
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include <iostream>

static void sep(const char* title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
    // Subject basic scenario
    sep("SUBJECT SCENARIO");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        AMateria* tmp;

        tmp = src->createMateria("ice");
        me->equip(tmp);                   // owned by me
        tmp = src->createMateria("cure");
        me->equip(tmp);                   // owned by me

        ICharacter* bob = new Character("bob");
        me->use(0, *bob);                 // * shoots an ice bolt at bob *
        me->use(1, *bob);                 // * heals bob's wounds *

        delete bob;
        delete me;
        delete src;
    }

    // Equip order, overflow, use on empty/invalid
    sep("EQUIP ORDER / OVERFLOW / INVALID USE");
    {
        Character me("me");
        MateriaSource src;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());

        AMateria* m0 = src.createMateria("ice");
        AMateria* m1 = src.createMateria("cure");
        AMateria* m2 = src.createMateria("ice");
        AMateria* m3 = src.createMateria("cure");
        AMateria* m4 = src.createMateria("ice"); // 5th → should not fit

        me.equip(m0);
        me.equip(m1);
        me.equip(m2);
        me.equip(m3);
        me.equip(m4);                      // inventory full → ignored, caller must delete
        delete m4;                         // avoid leak (not equipped)

        Character bob("bob");
        for (int i = 0; i < 4; ++i) me.use(i, bob); // use all filled slots
        me.use(-1, bob);                   // invalid → no-op
        me.use(4, bob);                    // invalid → no-op
    }

    // Unequip must NOT delete (caller is responsible)
    sep("UNEQUIP DOES NOT DELETE");
    {
        Character me("me");
        MateriaSource src;
        src.learnMateria(new Ice());

        AMateria* m = src.createMateria("ice");
        me.equip(m);                       // owned while equipped
        me.unequip(0);                     // ownership back to caller
        // m is still valid here; reuse or delete it
        Character bob("bob");
        m->use(bob);                       // still works
        delete m;                          // caller cleans up
    }

    // Character deep copy (copy-ctor and operator=)
    sep("CHARACTER DEEP COPY");
    {
        MateriaSource src;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());

        Character a("alice");
        a.equip(src.createMateria("ice"));
        a.equip(src.createMateria("cure"));

        Character b(a);                    // deep copy ctor
        Character c("charlie");
        c = a;                             // deep copy assignment

        Character t("target");
        a.use(0, t);                       // ice
        b.use(0, t);                       // independent ice
        c.use(1, t);                       // cure

        // mutate 'a' and ensure 'b'/'c' unaffected
        a.unequip(0);
        a.equip(src.createMateria("cure")); // now slot 0 is cure in 'a'
        a.use(0, t);                        // cure
        b.use(0, t);                        // still ice (proved deep)
        c.use(0, t);                        // still ice (proved deep)
    }

    // MateriaSource deep copy
    sep("MATERIASOURCE DEEP COPY");
    {
        MateriaSource s1;
        s1.learnMateria(new Ice());
        s1.learnMateria(new Cure());

        MateriaSource s2(s1);              // deep copy
        MateriaSource s3; s3 = s1;         // deep copy

        AMateria* a = s2.createMateria("ice");
        AMateria* b = s3.createMateria("cure");
        Character me("me"), bob("bob");
        me.equip(a); me.equip(b);
        me.use(0, bob);
        me.use(1, bob);
        // me will delete a/b in its destructor
    }

    sep("DONE");
    return 0;
}
