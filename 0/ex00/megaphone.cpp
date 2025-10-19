/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 00:58:32 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/13 10:00:16 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cctype>

void	megaphone(int ac, char **av)
{
	unsigned char	uc;
	int				i;
	int				j;

	if (ac < 1 || !av || !*av)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				uc = static_cast<unsigned char>(av[i][j]);
				
				std::cout << static_cast<char>(std::toupper(uc));
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	megaphone(ac - 1, av + 1);
	return (0);
}
