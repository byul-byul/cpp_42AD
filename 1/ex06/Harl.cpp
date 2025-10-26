/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:49:56 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 17:53:58 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"
# include <iostream>

Harl::Harl(void):
	_except_msg("EXCEPTION"),
	_debug_msg("DEBUG"),
	_info_msg("INFO"),
	_warn_msg("WARNING"),
	_error_msg("ERROR")
	{}

Harl::~Harl(void) {}

void	Harl::_debug(void) const
{
	std::cout << _debug_msg << std::endl;
}

void	Harl::_info(void) const
{
	std::cout << _info_msg << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << _warn_msg << std::endl;
}

void	Harl::_error(void) const
{
	std::cout << _error_msg << std::endl;
}

void	Harl::_except(void) const
{
	std::cout << _except_msg << std::endl;
}

void	Harl::complain(const std::string& level) const
{
	int	i = 0;

	static const char*	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (i != 4 && level != levels[i])
		i++;
	switch (i)
	{
		case 0:
			_debug();
		case 1:
			_info();
		case 2:
			_warning();
		case 3:
			_error();
			break;
		default:
			_except();
			break;
	}
}
