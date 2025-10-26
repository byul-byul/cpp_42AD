/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:02:01 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 12:39:35 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA(void);

		void		attack(void) const;

	private:
		HumanA(void);
		std::string	_name;
		Weapon&		_weapon;
};

#endif