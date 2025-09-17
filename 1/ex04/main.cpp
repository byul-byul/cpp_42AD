/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:55:29 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 14:05:11 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

const int	READ_BYTES_SIZE = 42;

void	replace(std::string filename, std::string target, std::string update)
{
	if (filename.empty() || target.empty() || update.empty())
	{
		std::cerr << "Incorrect arg value" << std::endl;
		return ;
	}
	
}

void	run_replace(int ac, char **av)
{
	if (ac != 3)
	{
		std::cerr << "Incorrect arg count" << std::endl;
		return ;
	}
	replace(av[0], av[1], av[2]);
}

int	main(int ac, char **av)
{
	run_replace(ac - 1, av + 1);
	return (0);
}
