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

# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

# include <iostream>

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
        wrongi->makeSound();   // вызовется WrongAnimal::makeSound()
        wrongmeta->makeSound();

        delete wrongi;         // если ~WrongAnimal не virtual, ~WrongCat не вызовется
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
        // Деструкторы сработают в конце блока (сначала Dog/Cat, затем Animal)
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

        // Никаких присваиваний вида: Animal a = d; // (срезка) — намеренно не делаем
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
        delete a; // ожидаем ~Dog(), затем ~Animal()
    }

    std::cout << "\n=== DELETE THROUGH BASE (WRONG) ===" << std::endl;
    {
        const WrongAnimal* a = new WrongCat();
        delete a; // если ~WrongAnimal не virtual — вызовется только ~WrongAnimal()
    }

    return 0;
}
