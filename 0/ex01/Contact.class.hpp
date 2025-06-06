/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:51:29 by bhajili           #+#    #+#             */
/*   Updated: 2025/05/06 15:40:09 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <string>
# include <iostream>

# define MAX_PRINT_LEN		10

class	Contact
{
	public:
		 Contact(void);
		~Contact(void);

		void	set_first_name(const std::string& first_name);
		void	set_last_name(const std::string& last_name);
		void	set_nick_name(const std::string& nick_name);
		void	set_phone_number(const std::string& phone_number);
		void	set_darkest_secret(const std::string& darkest_secret);

		std::string		get_first_name(void);
		std::string		get_last_name(void);
		std::string		get_nick_name(void);
		std::string		get_phone_number(void);
		std::string		get_darkest_secret(void);

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nick_name;
		std::string		_phone_number;
		std::string		_darkest_secret;

		std::string		_crop_line(const std::string& line);
};

#endif
