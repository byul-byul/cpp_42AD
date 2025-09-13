/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.namespace.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:32:47 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/13 14:10:38 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.namespace.hpp"

int	ft::ft_isdigits(const std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
		if (!isdigit(str[i]))
			return (0);
	return (1);
}

int	ft::ft_isalphas(const std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
		if (!isalpha(str[i]))
			return (0);
	return (1);
}

int	ft::ft_atoi(const std::string str)
{
	int	sum;
	int	i;
	int	sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sign * sum);
}

std::string	ft::ft_toupper(std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
		str[i] = toupper(str[i]);
	return (str);
}
