/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 10:37:25 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 10:37:25 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"
# include <iostream>

Animal::Animal( void ): type("Animal type")
{
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal( const Animal& original ): type(original.type)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal&  Animal::operator=(const Animal& right_operand)
{
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
        type = right_operand.type;
    return *this;
}

Animal::~Animal( void )
{
    std::cout << "Animal: Destructor called" << std::endl;
}

void    Animal::makeSound( void ) const
{
    std::cout << "Animal: makeSound() called" << std::endl;
}

const std::string&  Animal::getType( void ) const
{
    return type;
}
