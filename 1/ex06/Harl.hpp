/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:39:24 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 17:26:17 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <string>
# include <iostream>

class	Harl
{
	public:

		 Harl(void);
		~Harl(void);

		void		complain(std::string level);

	private:

		std::string _except_msg;
		std::string	_debug_msg;
		std::string	_info_msg;
		std::string	_warn_msg;
		std::string _error_msg;

		void		_debug(void);
		void		_info(void);
		void		_warning(void);
		void		_error(void);
		void		_except(void);

};

#endif