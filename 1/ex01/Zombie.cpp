/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:01:59 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/15 15:40:00 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	Zombie::_nextIndex = 0;

Zombie::Zombie(std::string name)
{
	_name = name;
	_nextIndex++;
	_index = _nextIndex;
	return ;
}

Zombie::Zombie(void)
{
	_nextIndex++;
	_index = _nextIndex;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << _index << ". " << _name << ": was destroyed" << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << _index << ". " << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}
