/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-28 16:29:59 by bh                #+#    #+#             */
/*   Updated: 2025-10-28 16:29:59 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
# include <iostream>

// ### Constructors & Destructors ###

FragTrap::FragTrap( void )
{
	_name         = "Default name";
	_hitPoints    = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap( const std::string& name ) : ClapTrap(name)
{
	_hitPoints    = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap param constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& original ) : ClapTrap(original)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& right_operand )
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &right_operand)
		ClapTrap::operator=(right_operand);
	return *this;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
}


// ############# public #############

void	FragTrap::attack( const std::string& target )
{
	if (!_isActive())
	{
		std::cout << "FragTrap " << _name
		          << " cannot attack (hp=" << _hitPoints
		          << ", ep=" << _energyPoints << ")" << std::endl;
		return ;
	}
	--_energyPoints;
	std::cout << "FragTrap " << _name
	          << " attacks " << target
	          << ", causing " << _attackDamage
	          << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys( void ) const
{
	std::cout << "FragTrap " << _name << " is requesting high fives! ----> ✋ <----." << std::endl;
}
