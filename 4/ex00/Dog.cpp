/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 12:19:57 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 12:19:57 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"
# include <iostream>

Dog::Dog( void ): Animal()
{
    std::cout << "Dog: Default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog( const Dog& original ): Animal(original)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog&  Dog::operator=(const Dog& right_operand)
{
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
        Animal::operator=(right_operand);
    return *this;
}

Dog::~Dog( void )
{
    std::cout << "Dog: Destructor called" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Woof!" << std::endl;
}
