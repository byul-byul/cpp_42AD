/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.namespace.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:32:47 by bhajili           #+#    #+#             */
/*   Updated: 2025/05/05 14:41:51 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.namespace.hpp"

int	ft::ft_isdigits(std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
		if (!isdigit(str[i]))
			return (0);
	return (1);
}

int	ft::ft_isalphas(std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
		if (!isalpha(str[i]))
			return (0);
	return (1);
}

std::string	ft::ft_toupper(std::string str)
{
	for (size_t i = 0; i < str.size(); ++i)
		str[i] = toupper(str[i]);
	return (str);
}
