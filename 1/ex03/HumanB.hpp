/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:02:01 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 13:35:27 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_CLASS_HPP
# define HUMAN_B_CLASS_HPP

# include <string>
# include <iostream>

# include "Weapon.hpp"

class	HumanB
{
	public:
		 HumanB(std::string name);
		 HumanB(void);
		~HumanB(void);

		void		attack(void);
		void		setWeapon(Weapon &weapon);
		Weapon		*getWeapon(void);

	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif