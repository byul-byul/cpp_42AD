/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:02:19 by bhajili           #+#    #+#             */
/*   Updated: 2025/05/05 19:51:35 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "ft.namespace.hpp"

void	welcomeMessage(void)
{
	std::cout << std::endl << "<>  Wellcome to the awesome PhoneBook session  <>";
	std::cout << std::endl << std::endl;
	std::cout << "   ***************** MENU ********************" << std::endl;
	std::cout << "   *   ADD    |     SEARCH     |    EXIT     *" << std::endl;
	std::cout << "   *******************************************" << std::endl;
}

void	myAwesomePhoneBook(PhoneBook& pb)
{
	std::string	input;

	welcomeMessage();
	while (1)
	{
		std::cout << std::endl << "Enter your command: ";
		if (!(std::getline(std::cin, input)))
			break ;
		input = ft::ft_toupper(input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else
			std::cout << "Wrong command, try again." << std::endl;
	}
}

int	main(void)
{
	PhoneBook	phonebook;

	myAwesomePhoneBook(phonebook);
	return (0);
}
