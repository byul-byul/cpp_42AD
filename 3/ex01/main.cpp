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

// main.cpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--- Construction chain test ---" << std::endl;
    {
        ScavTrap s1("Serena");
        ScavTrap s2;
    }
    std::cout << std::endl;

    ScavTrap a("Alpha");
    ScavTrap b("Bravo");

    std::cout << "\n--- Attack test (ScavTrap message) ---" << std::endl;
    a.attack("Bravo");   // should print ScavTrap-specific attack message
    a.attack("Bravo");
    std::cout << std::endl;

    // std::cout << "\n--- Damage test ---" << std::endl;
    // b.takeDamage(15);    // partial damage
    // b.takeDamage(90);    // drop HP to (possibly) near zero
    // b.takeDamage(1);     // damage on already “dead” or to zero
    // std::cout << std::endl;

    // std::cout << "\n--- Repair + energy drain test ---" << std::endl;
    // a.beRepaired(20);    // valid repair (consumes 1 EP)
    // for (int i = 0; i < 60; ++i)
    //     a.attack("Bravo"); // drain EP (ScavTrap starts with 50 EP)
    // a.beRepaired(5);     // should be denied (no EP)
    // std::cout << std::endl;

    // std::cout << "\n--- Guard mode test ---" << std::endl;
    // a.guardGate();       // ScavTrap unique ability
    // std::cout << std::endl;

    // std::cout << "\n--- Copy/assign test ---" << std::endl;
    // ScavTrap c = a;      // copy constructor
    // c.attack("Charlie");
    // ScavTrap d("Delta");
    // d = b;               // copy assignment
    // d.guardGate();
    // std::cout << std::endl;

    // // Extra coverage: polymorphism + virtual destructor correctness
    // std::cout << "\n--- Polymorphism test (virtual dispatch) ---" << std::endl;
    // {
    //     ClapTrap* p = new ScavTrap("Poly");
    //     p->attack("Target"); // must dispatch ScavTrap::attack()
    //     delete p;            // must call ~ScavTrap then ~ClapTrap
    // }
    // std::cout << std::endl;

    // // Extra coverage: zero HP denial for any action
    // std::cout << "\n--- Zero HP denial test ---" << std::endl;
    // {
    //     ScavTrap z("Zero");
    //     z.takeDamage(150);   // HP -> 0
    //     z.attack("Anyone");  // must be denied (no HP)
    //     z.beRepaired(10);    // must be denied (no HP)
    // }
    // std::cout << std::endl;

    std::cout << "End of test." << std::endl;
    return 0;
}
