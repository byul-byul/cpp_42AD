/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:01:59 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 07:30:30 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(const std::string& type): _type(type) {}

Weapon::Weapon(void): _type() {}

Weapon::~Weapon(void) {}

const std::string&	Weapon::getType(void) const
{
	return _type;
}

void	Weapon::setType(const std::string& type)
{
	_type = type;
}
