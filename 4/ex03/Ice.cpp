/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 08:49:55 by bh                #+#    #+#             */
/*   Updated: 2025-10-31 08:49:55 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"
# include "ICharacter.hpp"
# include <iostream>

Ice::Ice( void ) : AMateria( "ice" )
{
    std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice( const Ice& original ) : AMateria( original )
{
    std::cout << "Ice: Copy constructor called" << std::endl;
}

Ice&   Ice::operator=( const Ice& right_operand )
{
    std::cout << "Ice: Copy assignment operator called" << std::endl;
    if ( this != &right_operand )
        AMateria::operator=( right_operand );
    return *this;
}

Ice::~Ice( void )
{
    std::cout << "Ice: Destructor called" << std::endl;
}

AMateria*  Ice::clone( void ) const
{
    return new Ice( *this );
}

void    Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
