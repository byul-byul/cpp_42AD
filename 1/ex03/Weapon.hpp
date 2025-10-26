/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:02:01 by bhajili           #+#    #+#             */
/*   Updated: 2025/09/16 07:27:50 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
	public:
		explicit			Weapon(const std::string& type);
							Weapon(void);
							~Weapon(void);

		const std::string&	getType(void) const;
		void				setType(const std::string& type);

	private:
		std::string			_type;
};

#endif