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
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--- Construction chain test ---" << std::endl;
    {
        FragTrap f1("Fiona");   // should first construct ClapTrap, then FragTrap
        FragTrap f2;            // default-constructed FragTrap
    }
    std::cout << std::endl;

    FragTrap a("Alpha");
    FragTrap b("Bravo");

    std::cout << "\n--- Attack test (FragTrap message) ---" << std::endl;
    a.attack("Bravo");          // should print FragTrap-specific attack message
    a.attack("Bravo");
    std::cout << std::endl;

    std::cout << "\n--- Damage test ---" << std::endl;
    b.takeDamage(60);           // partial damage
    b.takeDamage(50);           // drop HP to 0 (or below → clamped to 0)
    b.takeDamage(1);            // damage on already “dead” object (must be denied)
    std::cout << std::endl;

    std::cout << "\n--- Repair + energy drain test ---" << std::endl;
    a.beRepaired(40);           // valid repair (consumes 1 EP)
    for (int i = 0; i < 110; ++i)
        a.attack("Bravo");      // drain EP (FragTrap starts with 100 EP)
    a.beRepaired(5);            // should be denied (no EP)
    std::cout << std::endl;

    std::cout << "\n--- High fives special ability ---" << std::endl;
    a.highFivesGuys();          // FragTrap unique ability
    std::cout << std::endl;

    std::cout << "\n--- Copy/assign test ---" << std::endl;
    FragTrap c = a;             // copy constructor
    c.attack("Charlie");
    FragTrap d("Delta");
    d = b;                      // copy assignment
    d.highFivesGuys();
    std::cout << std::endl;

    std::cout << "\n--- Polymorphism test (virtual dispatch) ---" << std::endl;
    {
        ClapTrap* p = new FragTrap("Poly");
        p->attack("Target");    // must dispatch FragTrap::attack()
        delete p;               // must call ~FragTrap then ~ClapTrap (virtual dtor)
    }
    std::cout << std::endl;

    std::cout << "\n--- Zero HP denial test ---" << std::endl;
    {
        FragTrap z("Zero");
        z.takeDamage(150);      // HP -> 0
        z.attack("Anyone");     // must be denied (no HP)
        z.beRepaired(10);       // must be denied (no HP)
        z.highFivesGuys();      // can still print ability message (no HP/EP required)
    }
    std::cout << std::endl;

    std::cout << "End of test." << std::endl;
    return 0;
}
