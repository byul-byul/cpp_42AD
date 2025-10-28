/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:49:56 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 17:25:57 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"
# include <iostream>
# include <cstddef>

Harl::Harl(void):
	_except_msg("[ Probably complaining about insignificant problems ]"),
	_debug_msg("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"),
	_info_msg("I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"),
	_warn_msg("I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."),
	_error_msg("This is unacceptable! I want to speak to the manager now.")
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

typedef void	(Harl::*harlFuncPtr)() const;

void	Harl::complain(const std::string& level) const
{
	static const char* levelList[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	static const std::size_t N = sizeof(levelList) / sizeof(levelList[0]);

	static const harlFuncPtr fn[] =
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error,
		&Harl::_except
	};

	std::size_t i = 0;
	while (i < N && level != levelList[i])
		++i;
	(this->*fn[i < N ? i : N])();
}

