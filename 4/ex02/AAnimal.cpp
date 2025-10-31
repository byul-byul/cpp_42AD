/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 10:37:25 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 10:37:25 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AAnimal.hpp"
# include <iostream>

AAnimal::AAnimal( void ): type("AAnimal type")
{
    std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& original ): type(original.type)
{
    std::cout << "AAnimal: Copy constructor called" << std::endl;
}

AAnimal&  AAnimal::operator=(const AAnimal& right_operand)
{
    std::cout << "AAnimal: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
        type = right_operand.type;
    return *this;
}

AAnimal::~AAnimal( void )
{
    std::cout << "AAnimal: Destructor called" << std::endl;
}

const std::string&  AAnimal::getType( void ) const
{
    return type;
}
