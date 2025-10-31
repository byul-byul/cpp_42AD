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

Dog::Dog( void ): AAnimal()
{
    std::cout << "Dog: Default constructor called" << std::endl;
    type = "Dog";
    _brain = new Brain();
}

Dog::Dog( const Dog& original ): AAnimal(original)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    _brain = new Brain(*original._brain);
}

Dog& Dog::operator=(const Dog& right_operand)
{
    std::cout << "Dog: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
    {
        AAnimal::operator=(right_operand);
        Brain* tmp = new Brain(*right_operand._brain); // может бросить
        delete _brain;
        _brain = tmp;
    }
    return *this;
}

Dog::~Dog( void )
{
    std::cout << "Dog: Destructor called" << std::endl;
    delete _brain;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Woof!" << std::endl;
}

const std::string& Dog::getIdea(int idx) const
{
    return _brain->getIdea(idx);
}

void Dog::setIdea(int idx, const std::string& idea)
{
    _brain->setIdea(idx, idea);
}
