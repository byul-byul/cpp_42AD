/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 04:02:52 by bh                #+#    #+#             */
/*   Updated: 2025-11-30 04:02:52 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

/* ------------ Canonical ------------ */

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", "DefaultTarget", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other)
{
}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/* ------------ Action ------------ */

void PresidentialPardonForm::executeAction() const
{
    std::cout << getTarget()
              << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}
