/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:51:29 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/14 11:21:43 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact
{
	public:
		 Contact(void);
		~Contact(void);

		std::string		get_first_name(void) const;
		std::string		get_last_name(void) const;
		std::string		get_nick_name(void) const;
		std::string		get_phone_number(void) const;
		std::string		get_darkest_secret(void) const;

		void			set_first_name(const std::string& first_name);
		void			set_last_name(const std::string& last_name);
		void			set_nick_name(const std::string& nick_name);
		void			set_phone_number(const std::string& phone_number);
		void			set_darkest_secret(const std::string& darkest_secret);

		void			print_aligned(void) const;
		void			print_contact_info(void) const;

		enum { max_print_len = 10 };

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nick_name;
		std::string		_phone_number;
		std::string		_darkest_secret;

		std::string		_crop_line(const std::string& line) const;
		void			_print_aligned_field(const std::string& value) const;

};

#endif
