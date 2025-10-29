/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 13:31:23 by bh                #+#    #+#             */
/*   Updated: 2025-10-29 13:31:23 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DiamondTrap.cpp

# include "DiamondTrap.hpp"
# include <iostream>

// ### Constructors & Destructors ###

DiamondTrap::DiamondTrap( void )
: ClapTrap("Default name_clap_name"), ScavTrap(), FragTrap(), _name("Default name")
{
	// Per subject: HP/AD from FragTrap, EP from ScavTrap
	_hitPoints    = 100; // FragTrap
	_energyPoints = 50;  // ScavTrap
	_attackDamage = 30;  // FragTrap
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string& name )
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints    = 100; // FragTrap
	_energyPoints = 50;  // ScavTrap
	_attackDamage = 30;  // FragTrap
	std::cout << "DiamondTrap param constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& original )
: ClapTrap(original), ScavTrap(original), FragTrap(original), _name(original._name)
{
	// Preserve combined stats
	_hitPoints    = original._hitPoints;
	_energyPoints = original._energyPoints;
	_attackDamage = original._attackDamage;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& right_operand )
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &right_operand)
	{
		ClapTrap::operator=(right_operand);
		_name         = right_operand._name;
		_hitPoints    = right_operand._hitPoints;
		_energyPoints = right_operand._energyPoints;
		_attackDamage = right_operand._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}


// ############# public #############

void	DiamondTrap::attack( const std::string& target )
{
	// Use ScavTrap's attack implementation (per subject)
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void ) const
{
	std::cout << "DiamondTrap name: " << _name
	          << " | ClapTrap name: " << ClapTrap::_name
	          << std::endl;
}
