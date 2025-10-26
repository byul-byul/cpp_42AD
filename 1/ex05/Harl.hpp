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

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class	Harl
{
	public:

		 Harl(void);
		~Harl(void);

		void	complain(const std::string& level) const;

	private:

		const std::string	_except_msg;
		const std::string	_debug_msg;
		const std::string	_info_msg;
		const std::string	_warn_msg;
		const std::string	_error_msg;

		void				_debug(void) const;
		void				_info(void) const;
		void				_warning(void) const;
		void				_error(void) const;
		void				_except(void) const;

};

#endif