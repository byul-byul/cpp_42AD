/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 08:49:58 by bh                #+#    #+#             */
/*   Updated: 2025-10-31 08:49:58 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
# include "ICharacter.hpp"
# include <iostream>

Cure::Cure( void ) : AMateria( "cure" )
{
    std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure( const Cure& original ) : AMateria( original )
{
    std::cout << "Cure: Copy constructor called" << std::endl;
}

Cure&   Cure::operator=( const Cure& right_operand )
{
    std::cout << "Cure: Copy assignment operator called" << std::endl;
    if ( this != &right_operand )
        AMateria::operator=( right_operand );
    return *this;
}

Cure::~Cure( void )
{
    std::cout << "Cure: Destructor called" << std::endl;
}

AMateria*  Cure::clone( void ) const
{
    return new Cure( *this );
}

void    Cure::use( ICharacter& target )
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
