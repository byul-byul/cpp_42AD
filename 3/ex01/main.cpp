/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-26 11:56:23 by bh                #+#    #+#             */
/*   Updated: 2025-10-26 11:56:23 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    // 1) Цепочка конструкторов/деструкторов (блок гарантирует вызов деструктора внутри main)
    std::cout << "\n--- Construction chain ---\n";
    {
        ScavTrap s("Serena");
        s.attack("Dummy");      // показывает, что dispatch идёт в ScavTrap::attack
        s.guardGate();          // уникальная способность
    }                           // здесь виден порядок деструкторов
    std::cout << std::endl;

    // 2) Базовые операции
    ScavTrap a("Alpha");
    ScavTrap b("Bravo");

    std::cout << "\n--- Attack test (override) ---\n";
    a.attack("Bravo");          // специфичное сообщение ScavTrap
    std::cout << std::endl;

    std::cout << "\n--- Damage to zero + denial ---\n";
    b.takeDamage(100);          // HP -> 0
    b.attack("Anyone");         // отказ (HP=0)
    b.beRepaired(5);            // отказ (HP=0)
    std::cout << std::endl;

    // 3) Копирование/присваивание
    std::cout << "\n--- Copy / Assign ---\n";
    ScavTrap c = a;             // copy ctor
    c.attack("Charlie");
    ScavTrap d("Delta");
    d = b;                      // copy assign (копируем состояние с HP=0)
    d.attack("Echo");           // отказ (унаследовано HP=0)
    std::cout << std::endl;

    // 4) Полиморфизм + виртуальный деструктор
    std::cout << "\n--- Polymorphism (virtual dispatch & dtor) ---\n";
    {
        ClapTrap* p = new ScavTrap("Poly");
        p->attack("Target");    // должен пойти в ScavTrap::attack()
        delete p;               // ~ScavTrap затем ~ClapTrap
    }
    std::cout << "\nEnd of test.\n";
    return 0;
}
