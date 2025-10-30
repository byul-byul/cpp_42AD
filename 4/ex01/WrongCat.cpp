/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 12:21:06 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 12:21:06 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"
# include <iostream>

WrongCat::WrongCat( void ): WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& original ): WrongAnimal(original)
{
    std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat&  WrongCat::operator=(const WrongCat& right_operand)
{
    std::cout << "WrongCat: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
        WrongAnimal::operator=(right_operand);
    return *this;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat: Destructor called" << std::endl;
}

void    WrongCat::makeSound( void ) const
{
    std::cout << "Wrong Meow!" << std::endl;
}
