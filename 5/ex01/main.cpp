/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-27 11:43:31 by bh                #+#    #+#             */
/*   Updated: 2025-11-27 11:43:31 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // --- Case 1: successful signing ---
    {
        Bureaucrat john("John", 40);
        Form f1("FormA", 50, 20);

        std::cout << f1 << std::endl;
        john.signForm(f1);
        std::cout << f1 << std::endl;
    }

    std::cout << "----" << std::endl;

    // --- Case 2: cannot sign (grade too low) ---
    {
        Bureaucrat bob("Bob", 100);
        Form f2("FormB", 20, 10);

        std::cout << f2 << std::endl;
        bob.signForm(f2);
        std::cout << f2 << std::endl;
    }

    std::cout << "----" << std::endl;

    // --- Case 3: incorrect form grades (constructor throws) ---
    try
    {
        Form bad("ImpossibleForm", 0, 10); // grade too high → invalid
    }
    catch (std::exception &e)
    {
        std::cout << "Exception creating form: " << e.what() << std::endl;
    }

    return 0;
}
