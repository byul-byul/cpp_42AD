/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 04:01:11 by bh                #+#    #+#             */
/*   Updated: 2025-11-30 04:01:11 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* ------------ Canonical ------------ */

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", "DefaultTarget", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other)
{
}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/* ------------ Action ------------ */

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* drilling noises *" << std::endl;

    std::srand(std::time(NULL));
    bool success = (std::rand() % 2) == 0;

    if (success)
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << getTarget() << "!" << std::endl;
}
