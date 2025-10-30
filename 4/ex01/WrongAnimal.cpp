/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 10:37:25 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 10:37:25 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"
# include <iostream>

WrongAnimal::WrongAnimal( void ): type("WrongAnimal type")
{
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& original ): type(original.type)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

WrongAnimal&  WrongAnimal::operator=(const WrongAnimal& right_operand)
{
    std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
        type = right_operand.type;
    return *this;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

void    WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal: makeSound() called" << std::endl;
}

const std::string&  WrongAnimal::getType( void ) const
{
    return type;
}
