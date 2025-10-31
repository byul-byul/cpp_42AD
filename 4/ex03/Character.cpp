/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:46:10 by bh                #+#    #+#             */
/*   Updated: 2025/10/31 17:32:33 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"
# include <iostream>

Character::Character( void ) : _name("noname")
{
    std::cout << "Character: Default constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
}

Character::Character( const std::string& name ) : _name(name)
{
    std::cout << "Character: String constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
}

Character::Character( const Character& original ) : _name(original._name)
{
    std::cout << "Character: Copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
    _deepCopyFrom(original);
}

Character&  Character::operator=( const Character& right_operand )
{
    std::cout << "Character: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
    {
        _name = right_operand._name;
        _clearInventory();
        _deepCopyFrom(right_operand);
    }
    return *this;
}

Character::~Character( void )
{
    std::cout << "Character: Destructor called" << std::endl;
    _clearInventory();
}

std::string const&  Character::getName( void ) const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i)
        if (_inventory[i] == m)
            return;

    for (int i = 0; i < 4; ++i)
        if (_inventory[i] == 0)
        {
            _inventory[i] = m;
            return;
        }
}

void    Character::unequip( int idx )
{
    if (idx < 0 || idx >= 4)
        return;
    _inventory[idx] = 0;
}

void    Character::use( int idx, ICharacter& target )
{
    if (idx < 0 || idx >= 4)
        return;
    if (_inventory[idx])
        _inventory[idx]->use(target);
}

void    Character::_clearInventory( void )
{
    for (int i = 0; i < 4; ++i)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = 0;
        }
    }
}

void    Character::_deepCopyFrom( const Character& other )
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
}
