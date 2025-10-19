/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:57:14 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/13 11:46:44 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "ft.namespace.hpp"
# include <cstddef>

# ifndef MAX_CONTACT_COUNT
#  define MAX_CONTACT_COUNT	8
# endif

# ifndef SUCCESS
#  define SUCCESS			0
# endif

# ifndef FAIL
#  define FAIL				1
# endif

class	PhoneBook
{
	public:
		 PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);

	private:
		Contact		_contact_list[MAX_CONTACT_COUNT];
		std::size_t	_contact_list_size;
		int			_last_updated_contact_index;

		void		_add_first_name(const std::string& value);
		void		_add_last_name(const std::string& value);
		void		_add_nick_name(const std::string& value);
		void		_add_phone_number(const std::string& value);
		void		_add_dark_secret(const std::string& value);
};

#endif