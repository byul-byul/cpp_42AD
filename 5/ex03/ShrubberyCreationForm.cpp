/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 03:58:54 by bh                #+#    #+#             */
/*   Updated: 2025-11-30 03:58:54 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/* ------------ Canonical ------------ */

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", "DefaultTarget", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other)
{
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/* ------------ Action ------------ */

void ShrubberyCreationForm::executeAction() const
{
    std::string fileName = getTarget() + "_shrubbery";
    std::ofstream file(fileName.c_str());

    if (!file)
        return; // сабжект не требует бросать исключение

    file <<
"       _-_       \n"
"    /~~   ~~\\   \n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\\\ //  ~ \n"
" _- -  | | _- _ \n"
"   _ - | |   -_ \n"
"       // \\\\     \n";

    file.close();
}
