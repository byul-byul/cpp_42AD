/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-28 16:29:59 by bh                #+#    #+#             */
/*   Updated: 2025-10-28 16:29:59 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"
# include <iostream>

// ### Constructors & Destructors ###

ScavTrap::ScavTrap( void )
{
	_name         = "Default name";
	_hitPoints    = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name)
{
	_hitPoints    = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap param constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& original ) : ClapTrap(original)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& right_operand )
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &right_operand)
		ClapTrap::operator=(right_operand);
	return *this;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
}


// ############# public #############

void	ScavTrap::attack( const std::string& target )
{
	if (!_isActive())
	{
		std::cout << "ScavTrap " << _name
		          << " cannot attack (hp=" << _hitPoints
		          << ", ep=" << _energyPoints << ")" << std::endl;
		return ;
	}
	--_energyPoints;
	std::cout << "ScavTrap " << _name
	          << " attacks " << target
	          << ", causing " << _attackDamage
	          << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate( void ) const
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
