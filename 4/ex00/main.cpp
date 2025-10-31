/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 10:30:00 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 10:30:00 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
    std::cout << "=== NORMAL CASE ===" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j    = new Dog();
        const Animal* i    = new Cat();

        std::cout << j->getType() << std::endl; // Dog
        std::cout << i->getType() << std::endl; // Cat

        i->makeSound(); // Meow!
        j->makeSound(); // Woof!
        meta->makeSound();

        delete i;
        delete j;
        delete meta;
    }

    std::cout << "\n=== WRONG CASE (no virtual) ===" << std::endl;
    {
        const WrongAnimal* wrongmeta = new WrongAnimal();
        const WrongAnimal* wrongi    = new WrongCat();

        std::cout << wrongi->getType() << std::endl; // WrongCat
        wrongi->makeSound();   // calls WrongAnimal::makeSound()
        wrongmeta->makeSound();

        delete wrongi;         // if ~WrongAnimal is not virtual, ~WrongCat will not be called
        delete wrongmeta;
    }

    std::cout << "\n=== COPY/ASSIGN TESTS ===" << std::endl;
    {
        Dog d1;
        Dog d2(d1);
        Dog d3; d3 = d1;

        Cat c1;
        Cat c2(c1);
        Cat c3; c3 = c1;
        // Destructors will run at the end of the block (derived first, then base)
    }

    std::cout << "\n=== REFERENCE POLYMORPHISM ===" << std::endl;
    {
        Dog d;  Cat c;
        const Animal& ar1 = d;
        const Animal& ar2 = c;
        ar1.makeSound(); // Woof!
        ar2.makeSound(); // Meow!
    }

    std::cout << "\n=== GETTYPE & NO SLICING ===" << std::endl;
    {
        Dog d;  Cat c;
        std::cout << d.getType() << std::endl; // Dog
        std::cout << c.getType() << std::endl; // Cat

        // No assignments like: Animal a = d; // slicing intentionally avoided
    }

    std::cout << "\n=== WRONG CALLS (BASE VS DERIVED) ===" << std::endl;
    {
        WrongCat wc;
        const WrongAnimal* wa = &wc;
        wa->makeSound(); // WrongAnimal::makeSound()
        wc.makeSound();  // "Wrong Meow!"
    }

    std::cout << "\n=== DELETE THROUGH BASE (NORMAL) ===" << std::endl;
    {
        const Animal* a = new Dog();
        delete a; // expect ~Dog() then ~Animal()
    }

    std::cout << "\n=== DELETE THROUGH BASE (WRONG) ===" << std::endl;
    {
        const WrongAnimal* a = new WrongCat();
        delete a; // if ~WrongAnimal is not virtual, only ~WrongAnimal() will be called
    }

    return 0;
}
