/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 09:13:39 by bh                #+#    #+#             */
/*   Updated: 2025-10-31 09:13:39 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"
# include <iostream>

MateriaSource::MateriaSource( void )
{
    std::cout << "MateriaSource: Default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _storage[i] = 0;
}

MateriaSource::MateriaSource( const MateriaSource& original )
{
    std::cout << "MateriaSource: Copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _storage[i] = 0;
    _deepCopyFrom( original );
}

MateriaSource&   MateriaSource::operator=( const MateriaSource& right_operand )
{
    std::cout << "MateriaSource: Copy assignment operator called" << std::endl;
    if ( this != &right_operand )
    {
        _clearStorage();
        _deepCopyFrom( right_operand );
    }
    return *this;
}

MateriaSource::~MateriaSource( void )
{
    std::cout << "MateriaSource: Destructor called" << std::endl;
    _clearStorage();
}

void    MateriaSource::learnMateria( AMateria* m )
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i)
    {
        if (_storage[i] == 0)
        {
            _storage[i] = m->clone(); // store a copy (template)
            delete m;
            return;
        }
    }
    delete m; 
}

AMateria*   MateriaSource::createMateria( std::string const& type )
{
    for (int i = 0; i < 4; ++i)
        if ( _storage[i] && _storage[i]->getType() == type )
            return _storage[i]->clone();
    return 0; // unknown type
}

void    MateriaSource::_clearStorage( void )
{
    for (int i = 0; i < 4; ++i)
    {
        if ( _storage[i] )
        {
            delete _storage[i];
            _storage[i] = 0;
        }
    }
}

void    MateriaSource::_deepCopyFrom( const MateriaSource& other )
{
    for (int i = 0; i < 4; ++i)
    {
        if ( other._storage[i] )
            _storage[i] = other._storage[i]->clone();
        else
            _storage[i] = 0;
    }
}
