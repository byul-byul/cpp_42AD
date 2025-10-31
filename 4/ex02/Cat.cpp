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

Cat::Cat( void ): AAnimal()
{
    std::cout << "Cat: Default constructor called" << std::endl;
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat( const Cat& original ): AAnimal(original)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    _brain = new Brain(*original._brain);
}

Cat& Cat::operator=(const Cat& right_operand)
{
    std::cout << "Cat: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
    {
        AAnimal::operator=(right_operand);
        Brain* tmp = new Brain(*right_operand._brain);
        delete _brain;
        _brain = tmp;
    }
    return *this;
}

Cat::~Cat( void )
{
    std::cout << "Cat: Destructor called" << std::endl;
    delete _brain;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow!" << std::endl;
}

const std::string& Cat::getIdea(int idx) const
{
    return _brain->getIdea(idx);
}

void Cat::setIdea(int idx, const std::string& idea)
{
    _brain->setIdea(idx, idea);
}
