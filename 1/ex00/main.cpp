/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:01:51 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/15 13:39:29 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int	main( void )
{
	Zombie	*heap_zombie = newZombie("Heapman");

	heap_zombie->announce();
	delete heap_zombie;
	randomChump("Stackman");
	return (0);
}
