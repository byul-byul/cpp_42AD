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
#include <iostream>

int main()
{
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    std::cout << "\n--- Attack test ---\n";
    a.attack("Bravo");          // regular attack
    a.attack("Bravo");          // another attack
    std::cout << std::endl;

    std::cout << "\n--- Damage test ---\n";
    b.takeDamage(5);            // partial damage
    b.takeDamage(10);           // reduce to 0 HP
    b.takeDamage(3);            // damage on an already "dead" object
    std::cout << std::endl;

    std::cout << "\n--- Repair test ---\n";
    a.beRepaired(5);            // normal repair
    for (int i = 0; i < 10; ++i)
        a.attack("Bravo");      // drain all energy
    a.beRepaired(5);            // repair attempt without energy (should be denied)
    std::cout << std::endl;

    std::cout << "\n--- Copy test ---\n";
    ClapTrap c = a;             // invoke copy constructor
    c.attack("Charlie");
    std::cout << std::endl;

    std::cout << "End of test.\n";
    return 0;
}
