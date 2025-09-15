/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:02:01 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/15 15:38:13 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <string>
# include <iostream>

class	Zombie
{
	public:
		 Zombie(std::string name);
		 Zombie(void);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);

	private:
		std::string	_name;
		static int	_nextIndex;
		int			_index;
};

#endif