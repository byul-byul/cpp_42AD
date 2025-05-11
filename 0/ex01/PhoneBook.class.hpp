/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:57:14 by bhajili           #+#    #+#             */
/*   Updated: 2025/05/06 18:34:25 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# define MAX_CONTACT_COUNT	8

# include <iostream>
# include "Contact.class.hpp"
# include "ft.namespace.hpp"

class	PhoneBook
{
	public:
		 PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);

	private:
		Contact		_contact_list[MAX_CONTACT_COUNT];
		size_t		_contact_list_size;
		int			_last_updated_contact_index;
};

#endif