/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 04:07:09 by bh                #+#    #+#             */
/*   Updated: 2025-11-30 04:07:09 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    std::cout << "\n--- Test 1: valid forms ---" << std::endl;
    {
        AForm *f1 = intern.makeForm("shrubbery creation", "home");
        AForm *f2 = intern.makeForm("robotomy request", "Bender");
        AForm *f3 = intern.makeForm("presidential pardon", "Arthur");

        if (f1)
        {
            boss.signForm(*f1);
            boss.executeForm(*f1);
            delete f1;
        }

        if (f2)
        {
            boss.signForm(*f2);
            boss.executeForm(*f2);
            delete f2;
        }

        if (f3)
        {
            boss.signForm(*f3);
            boss.executeForm(*f3);
            delete f3;
        }
    }

    std::cout << "\n--- Test 2: invalid form ---" << std::endl;
    {
        AForm *f = intern.makeForm("some weird form", "nobody");
        if (f)
            delete f;
    }

    std::cout << "\n--- Test 3: mid-level bureaucrat tries executing ---" << std::endl;
    {
        Bureaucrat mid("Mid", 50);

        AForm *f = intern.makeForm("robotomy request", "HAL9000");
        if (f)
        {
            mid.signForm(*f);
            mid.executeForm(*f);  // will fail because exec grade is 45
            boss.executeForm(*f); // boss executes successfully
            delete f;
        }
    }

    std::cout << "\n--- Test 4: executing unsigned form ---" << std::endl;
    {
        AForm *f = intern.makeForm("shrubbery creation", "garden");
        if (f)
        {
            boss.executeForm(*f); // error: not signed
            delete f;
        }
    }

    return 0;
}
