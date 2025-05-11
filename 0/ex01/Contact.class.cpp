/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:55:30 by bhajili           #+#    #+#             */
/*   Updated: 2025/05/06 15:42:52 by bhajili          ###   ########.fr       */
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
	this->_first_name = first_name;
}

void	Contact::set_last_name(const std::string& last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nick_name(const std::string& nick_name)
{
	this->_nick_name = nick_name;
}

void	Contact::set_phone_number(const std::string& phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::set_darkest_secret(const std::string& darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string	Contact::get_first_name(void)
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->_last_name);
}

std::string	Contact::get_nick_name(void)
{
	return (this->_nick_name);
}

std::string	Contact::get_phone_number(void)
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->_darkest_secret);
}

std::string	_crop_line(const std::string &str)
{
	if (str.size() > MAX_PRINT_LEN)
		return (str.substr(0, 9) + ".");
	return (str);
}
