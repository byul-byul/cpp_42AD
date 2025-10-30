/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 12:21:06 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 12:21:06 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"
# include <iostream>

Cat::Cat( void ): Animal()
{
    type = "Cat";
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat( const Cat& original ): Animal(original)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat&  Cat::operator=(const Cat& right_operand)
{
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
        Animal::operator=(right_operand);
    return *this;
}

Cat::~Cat( void )
{
    std::cout << "Cat: Destructor called" << std::endl;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow!" << std::endl;
}
