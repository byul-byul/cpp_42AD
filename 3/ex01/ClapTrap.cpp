/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-26 16:21:27 by bh                #+#    #+#             */
/*   Updated: 2025-10-26 16:21:27 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include <iostream>

ClapTrap::ClapTrap( void ):
    _name("Default name"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
    {
        std::cout << "ClapTrap: Default constructor called" << std::endl;
    }

ClapTrap::ClapTrap( const std::string& name ):
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
    {
        std::cout << "PClapTrap: arameter constructor called" << std::endl;
    }

ClapTrap::ClapTrap( const ClapTrap& original ):
    _name(original._name),
    _hitPoints(original._hitPoints),
    _energyPoints(original._energyPoints),
    _attackDamage(original._attackDamage)
    {
        std::cout << "ClapTrap: Copy constructor called" << std::endl;
    }

ClapTrap&  ClapTrap::operator=(const ClapTrap& right_operand)
{
    std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
    if (this != &right_operand)
    {
        this->_name         = right_operand._name;
        this->_hitPoints    = right_operand._hitPoints;
        this->_energyPoints = right_operand._energyPoints;
        this->_attackDamage = right_operand._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap: Destructor called" << std::endl;
}

bool    ClapTrap::_hasHitPoints( void ) const
{
    return _hitPoints > 0;
}

bool    ClapTrap::_hasEnergyPoints( void ) const
{
    return _energyPoints > 0;
}

bool    ClapTrap::_isActive( void ) const
{
    return _hasHitPoints() && _hasEnergyPoints();
}

void ClapTrap::attack(const std::string& target)
{
    if (!_isActive())
    {
        std::cout << "ClapTrap " << _name
                  << " cannot attack (hp=" << _hitPoints
                  << ", ep=" << _energyPoints << ")" << std::endl;
        return ;
    }
    --_energyPoints;
    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!_hasHitPoints())
    {
        std::cout << "ClapTrap " << _name
                  << " is already destroyed and can't take more damage." << std::endl;
        return ;
    }

    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;

    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage! (HP = " << _hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!_isActive())
    {
        std::cout << "ClapTrap " << _name
                  << " cannot repair itself (hp=" << _hitPoints
                  << ", ep=" << _energyPoints << ")" << std::endl;
        return;
    }

    --_energyPoints;
    _hitPoints += amount;

    std::cout << "ClapTrap " << _name
              << " repairs itself for " << amount
              << " points! (HP = " << _hitPoints
              << ", EP = " << _energyPoints << ")" << std::endl;
}
