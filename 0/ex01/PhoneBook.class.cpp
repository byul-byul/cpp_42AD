/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:06:14 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/14 11:21:07 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

// ### Constructors & Destructors ###

PhoneBook::PhoneBook(void)
{
	_contact_list_size = 0;
	_last_updated_contact_index = -1;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}


// ############# public #############

void	PhoneBook::add(void)
{
	std::string	label;

	label = "";
	if (_last_updated_contact_index >= MAX_CONTACT_COUNT - 1)
		_last_updated_contact_index = -1;
	_last_updated_contact_index++;
	if (_contact_list_size < MAX_CONTACT_COUNT)
		_contact_list_size++;
	_add_first_name(label);
	_add_last_name(label);
	_add_nick_name(label);
	_add_phone_number(label);
	_add_dark_secret(label);
}

void	PhoneBook::search(void)
{
	size_t		i = 0;
	std::string	input;
	int			atoi;

	if (_contact_list_size <= 0)
	{
		std::cout << "Contact list is empty!" << std::endl;
		return ;
	}
	while (i < _contact_list_size)
	{
		std::cout << "\t" << i + 1 ;
		_contact_list[i].print_aligned();
		std::cout << std::endl;
		i++;
	}
	std::cout << "Select contact index for more details: ";
	if (!std::getline(std::cin, input))
		return ;
	atoi = ft::ft_atoi(input);
	if (atoi > 0 && atoi < MAX_CONTACT_COUNT)
		_contact_list[atoi - 1].print_contact_info();
	else
		std::cout << "Wrong index!" << std::endl;
}


// ############# private #############

void	PhoneBook::_add_first_name(const std::string& value)
{
	std::string	label;

	if (value.empty())
	{
		while (TRUE)
		{
			std::cout << "Enter first name: ";
			if (!std::getline(std::cin, label))
				break ;
			if (label.size() <= 0 || !ft::ft_isalphas(label))
				std::cout << "Name should contains only letters and cannot be blank" << std::endl;
			else
				break ;
		}
	}
	else
		label = value;
	_contact_list[_last_updated_contact_index].set_first_name(label);
}

void	PhoneBook::_add_last_name(const std::string& value)
{
	std::string	label;

	if (value.empty())
	{
		while (TRUE)
		{
			std::cout << "Enter last name: ";
			if (!std::getline(std::cin, label))
				break ;
			if (label.size() <= 0 || !ft::ft_isalphas(label))
				std::cout << "Name should contains only letters and cannot be blank" << std::endl;
			else
				break ;
		}
	}
	else
		label = value;
	_contact_list[_last_updated_contact_index].set_last_name(label);
}

void	PhoneBook::_add_nick_name(const std::string& value)
{
	std::string	label;

	if (value.empty())
	{
		std::cout << "Enter nick name: ";
		if (!std::getline(std::cin, label))
			return ;
		if (label.size() <= 0)
			label = "<empty>";
	}
	else
		label = value;
	_contact_list[_last_updated_contact_index].set_nick_name(label);
}

void	PhoneBook::_add_phone_number(const std::string& value)
{
	std::string	label;

	if (value.empty() || !ft::ft_isdigits(value))
	{
		while (TRUE)
		{
			std::cout << "Enter phone number: ";
			if (!std::getline(std::cin, label))
				break ;
			if (label.size() <= 1 || !ft::ft_isdigits(label))
				std::cout << "Number should contains only digits and have at least two numerals" << std::endl;
			else
				break ;
		}
	}
	else
		label = value;
	_contact_list[_last_updated_contact_index].set_phone_number(label);
}

void	PhoneBook::_add_dark_secret(const std::string& value)
{
	std::string	label;

	if (value.empty())
	{
		std::cout << "Enter dark secret: ";
		if (!std::getline(std::cin, label))
			return ;
		if (label.size() <= 0)
			label = "<empty>";
	}
	else
		label = value;
	_contact_list[_last_updated_contact_index].set_darkest_secret(label);
}
