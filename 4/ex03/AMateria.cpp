/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 06:30:05 by bh                #+#    #+#             */
/*   Updated: 2025-10-31 06:30:05 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"
# include <iostream>

AMateria::AMateria( void ) : type("amateria")
{
    std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria( const std::string& t ) : type(t)
{
    std::cout << "AMateria: String constructor called" << std::endl;
}

AMateria::AMateria( const AMateria& original ) : type(original.type)
{
    std::cout << "AMateria: Copy constructor called" << std::endl;
}

AMateria&  AMateria::operator=( const AMateria& right_operand )
{
    std::cout << "AMateria: Copy assignment operator called" << std::endl;
    (void)right_operand; // type is identity; nothing to copy
    return *this;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria: Destructor called" << std::endl;
}

std::string const&  AMateria::getType( void ) const
{
    return this->type;
}

void    AMateria::use( ICharacter& target )
{
    (void)target; // no-op in base
}
