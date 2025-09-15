/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:01:51 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/15 15:36:20 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main( void )
{
	int			i = 0;
	int			N = 9;
	Zombie		*heap_zombie_horde = zombieHorde(N, "Heapman");

	while (i < N)
	{
		heap_zombie_horde[i].announce();
		i++;
	}
	delete [] heap_zombie_horde;
	return (0);
}
