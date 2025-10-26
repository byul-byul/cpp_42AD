/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:14:38 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/15 17:16:35 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int	main(void)
{
	std::string		brain_speech = "HI THIS IS BRAIN";

	std::string		*stringPTR = &brain_speech;
	std::string		&stringREF = brain_speech;

	std::cout << "the address in memory of the string:\t\t\t" << &brain_speech << std::endl;
	std::cout << "the address in memory of the string by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "the address in memory of the string by stringREF:\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "the string itself:\t\t\t" << brain_speech << std::endl;
	std::cout << "the string by stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "the string by stringREF:\t\t" << stringREF << std::endl;

	return (0);
}
