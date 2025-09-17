/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:14:51 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 17:22:09 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	complaint;

	if (ac != 2)
		std::cout << "provide valid arg" <<std::endl;
	else
		complaint.complain(av[1]);
	return (0);
}
