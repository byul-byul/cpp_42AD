/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:01:59 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 13:40:57 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
	return ;
}

HumanB::HumanB(void)
{
	return ;
}

HumanB::~HumanB(void)
{
	_weapon = NULL;
	return ;
}

void	HumanB::attack(void)
{
	if (!_weapon)
		std::cout << _name << " has no weapon!" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

Weapon	*HumanB::getWeapon(void)
{
	return _weapon;
}
