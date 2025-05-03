/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:58:32 by bhajili           #+#    #+#             */
/*   Updated: 2025/05/04 01:03:47 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define DEFAULT_MSG	"* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void	megaphone(int ac, char **av)
{
	if (ac < 1)
		std::cout << DEFAULT_MSG;
	else
	{
		while (*av)
		{
			while (**av)
			{
				if (std::islower(**av))
					std::cout << (char)std::toupper(**av);
				else
					std::cout << **av;
				(*av)++;
			}
			av++;
		}
	}
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	megaphone(ac - 1, av + 1);
	return (0);
}
