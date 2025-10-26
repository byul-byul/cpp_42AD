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

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <string>
# include "Weapon.hpp"

class	HumanB
{
	public:
		explicit	HumanB(const std::string& name);
					HumanB(void);
					~HumanB(void);

		void		attack(void) const;
		void		setWeapon(Weapon& weapon);
		Weapon		*getWeapon(void) const;

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif