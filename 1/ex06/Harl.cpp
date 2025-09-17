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

Harl::Harl(void)
{
	_except_msg = "EXCEPTION";
	_debug_msg = "DEBUG";
	_info_msg = "INFO";
	_warn_msg = "WARNING";
	_error_msg = "ERROR";
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::_debug(void)
{
	std::cout << _debug_msg << std::endl;
}

void	Harl::_info(void)
{
	std::cout << _info_msg << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << _warn_msg << std::endl;
}

void	Harl::_error(void)
{
	std::cout << _error_msg << std::endl;
}

void	Harl::_except(void)
{
	std::cout << _except_msg << std::endl;
}

typedef void	(Harl::*harlFuncPtr)();

void	Harl::complain(std::string level)
{
	int 			i = 0;
	std::string 	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

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
