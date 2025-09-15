/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:20:40 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/15 15:33:50 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	int		i = 0;
	Zombie*	heap_zombie_horde = new Zombie[N];

	while (i < N)
	{
		heap_zombie_horde[i].setName(name);
		i++;
	}
	return (heap_zombie_horde);
}
