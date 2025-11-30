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

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // Предполагается, что в ex02:
    // void Bureaucrat::signForm(AForm &form);
    // void Bureaucrat::executeForm(AForm const &form) const;

    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 50);
    Bureaucrat low("Low", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm   robo("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "--- Initial forms ---" << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;
    std::cout << "---------------------" << std::endl;

    // --- Shrubbery: low не может подписать, boss подписывает и выполняет ---
    std::cout << "\n[ ShrubberyCreationForm tests ]" << std::endl;
    low.signForm(shrub);
    boss.signForm(shrub);

    low.executeForm(shrub);
    boss.executeForm(shrub);

    // --- Robotomy: mid может подписать, boss выполняет ---
    std::cout << "\n[ RobotomyRequestForm tests ]" << std::endl;
    low.signForm(robo);
    mid.signForm(robo);

    low.executeForm(robo);
    mid.executeForm(robo);
    boss.executeForm(robo);

    // --- Pardon: только boss может подписать и выполнить ---
    std::cout << "\n[ PresidentialPardonForm tests ]" << std::endl;
    mid.signForm(pardon);
    boss.signForm(pardon);

    mid.executeForm(pardon);
    boss.executeForm(pardon);

    return 0;
}
