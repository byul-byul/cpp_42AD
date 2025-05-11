/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:06:14 by bhajili           #+#    #+#             */
/*   Updated: 2025/05/11 16:02:32 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	_contact_list_size = 0;
	_last_updated_contact_index = -1;
	std::cout << "PhoneBook class constructor was called!" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook class destructor was called!" << std::endl;
	return ;
}

void	PhoneBook::add(void)
{
	std::cout << "PhoneBook::add() was called!" << std::endl;
	int			i;
	std::string	label;

	if (_last_updated_contact_index >= MAX_CONTACT_COUNT - 1)
		_last_updated_contact_index = -1;
	_last_updated_contact_index++;
	if (_contact_list_size < MAX_CONTACT_COUNT)
		_contact_list_size++;
	i = _last_updated_contact_index;
	while (1)
	{
		std::cout << "Enter first name: ";
		if (!(std::getline(std::cin, label)))
			break ;
		if (label.size() > 0 && ft::ft_isalphas(label))
		{
			_contact_list[i].set_first_name(label);
			break ;
		}
		else
			std::cout << "Name should contains only letters and cannot be blank" << std::endl;
	}
	while (1)
	{
		std::cout << "Enter last name: ";
		if (!(std::getline(std::cin, label)))
			break ;
		if (label.size() > 0 && ft::ft_isalphas(label))
		{
			_contact_list[i].set_last_name(label);
			break ;
		}
		else
			std::cout << "Name should contains only letters and cannot be blank" << std::endl;
	}
	std::cout << "Enter nick name: ";
	if (!(std::getline(std::cin, label)))
		return ;
	if (label.size() < 1)
		label = "<empty>";
	_contact_list[i].set_nick_name(label);
	while (1)
	{
		std::cout << "Enter phone number: ";
		if (!(std::getline(std::cin, label)))
			break ;
		if (label.size() > 1 && ft::ft_isdigits(label))
		{
			_contact_list[i].set_phone_number(label);
			break ;
		}
		else
			std::cout << "Number should contains only digits and have at least two numerals" << std::endl;
	}
	std::cout << "Enter darkest secret: ";
	if (!(std::getline(std::cin, label)))
		return ;
	if (label.size() < 1)
		label = "<empty>";
	_contact_list[i].set_darkest_secret(label);
}

void	PhoneBook::search(void)
{
	std::cout << "PhoneBook::search() was called!" << std::endl;
	size_t	i = 0;

	while (i < _contact_list_size)
	{
		std::cout << _contact_list[i].get_first_name() << std::endl;
		i++;
	}
}
