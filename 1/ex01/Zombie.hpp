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

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	public:
		explicit	Zombie(const std::string& name);
					Zombie(void);
					~Zombie(void);

		void		announce(void) const;
		void		setName(const std::string& name);

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif