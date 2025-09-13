/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:55:30 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/13 13:59:43 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	std::cout << "Contact class constructor was called!" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact class destructor was called!" << std::endl;
	return ;
}

void	Contact::set_first_name(const std::string& first_name)
{
	_first_name = first_name;
}

void	Contact::set_last_name(const std::string& last_name)
{
	_last_name = last_name;
}

void	Contact::set_nick_name(const std::string& nick_name)
{
	_nick_name = nick_name;
}

void	Contact::set_phone_number(const std::string& phone_number)
{
	_phone_number = phone_number;
}

void	Contact::set_darkest_secret(const std::string& darkest_secret)
{
	_darkest_secret = darkest_secret;
}

void	Contact::_print_aligned_field(const std::string& value)
{
	int	diff;

	if (value.size() > max_print_len)
		std::cout << _crop_line(value);
	else
	{
		diff = max_print_len - value.size();
		while (diff--)
			std::cout << " ";
		std::cout << value;
	}
}

void	Contact::print_aligned(void)
{
	std::cout << "|";
	_print_aligned_field(get_first_name());
	std::cout << "|";
	_print_aligned_field(get_last_name());
	std::cout << "|";
	_print_aligned_field(get_nick_name());
	std::cout << "|";
}

void	Contact::print_contact_info(void)
{
	std::cout << "first name:\t" << get_first_name() << std::endl;
	std::cout << "last name:\t" << get_last_name() << std::endl;
	std::cout << "nick name:\t" << get_nick_name() << std::endl;
	std::cout << "phone number:\t" << get_phone_number() << std::endl;
	std::cout << "darkest secret:\t" << get_darkest_secret() << std::endl;
}

std::string	Contact::get_first_name(void)
{
	return (_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (_last_name);
}

std::string	Contact::get_nick_name(void)
{
	return (_nick_name);
}

std::string	Contact::get_phone_number(void)
{
	return (_phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (_darkest_secret);
}

std::string	Contact::_crop_line(const std::string& line)
{
	if (line.size() > max_print_len)
		return (line.substr(0, max_print_len - 1) + ".");
	return (line);
}
