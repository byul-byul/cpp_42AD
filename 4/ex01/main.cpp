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

// main.cpp (ex01)
# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"

# include <iostream>

int main() {
    std::cout << "=== ARRAY OF ANIMALS (HALF DOGS / HALF CATS) ===" << std::endl;
    {
        const int N = 6;
        const Animal* zoo[N];

        for (int i = 0; i < N/2; ++i)   zoo[i]      = new Dog();
        for (int i = N/2; i < N; ++i)   zoo[i]      = new Cat();

        for (int i = 0; i < N; ++i)     zoo[i]->makeSound();

        // delete через базовый указатель — проверка виртуальных деструкторов
        for (int i = 0; i < N; ++i)     delete zoo[i];
    }

    std::cout << "\n=== DEEP COPY: DOG (copy-ctor) ===" << std::endl;
    {
        Dog d1;
        d1.setIdea(0, "bone");
        Dog d2(d1);                 // deep copy
        d1.setIdea(0, "meat");      // меняем исходник
        std::cout << "d1[0]: " << d1.getIdea(0) << std::endl; // meat
        std::cout << "d2[0]: " << d2.getIdea(0) << std::endl; // bone  (должно отличаться)
    }

    std::cout << "\n=== DEEP COPY: CAT (copy-ctor) ===" << std::endl;
    {
        Cat c1;
        c1.setIdea(1, "nap");
        Cat c2(c1);                 // deep copy
        c1.setIdea(1, "fish");      // меняем исходник
        std::cout << "c1[1]: " << c1.getIdea(1) << std::endl; // fish
        std::cout << "c2[1]: " << c2.getIdea(1) << std::endl; // nap   (должно отличаться)
    }

    std::cout << "\n=== DEEP COPY: ASSIGNMENT (Dog & Cat) ===" << std::endl;
    {
        Dog d1; Dog d3;
        d1.setIdea(2, "run");
        d3 = d1;                    // operator= deep copy
        d1.setIdea(2, "sleep");     // меняем исходник
        std::cout << "d1[2]: " << d1.getIdea(2) << std::endl; // sleep
        std::cout << "d3[2]: " << d3.getIdea(2) << std::endl; // run   (должно отличаться)

        Cat c1; Cat c3;
        c1.setIdea(3, "climb");
        c3 = c1;                    // operator= deep copy
        c1.setIdea(3, "hunt");      // меняем исходник
        std::cout << "c1[3]: " << c1.getIdea(3) << std::endl; // hunt
        std::cout << "c3[3]: " << c3.getIdea(3) << std::endl; // climb (должно отличаться)
    }

    std::cout << "\n=== POLYMORPHIC DELETE SANITY ===" << std::endl;
    {
        const Animal* a = new Dog();
        const Animal* b = new Cat();
        delete a; // должен вызвать ~Dog() затем ~Animal()
        delete b; // должен вызвать ~Cat() затем ~Animal()
    }

    return 0;
}
