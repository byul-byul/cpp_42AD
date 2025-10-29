/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-29 13:31:26 by bh                #+#    #+#             */
/*   Updated: 2025-10-29 13:31:26 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class   DiamondTrap : public ScavTrap, public FragTrap
{
    public:

                        DiamondTrap( void );
        explicit        DiamondTrap( const std::string& name );
                        DiamondTrap( const DiamondTrap& original );
                        DiamondTrap& operator=( const DiamondTrap& right_operand );
        virtual         ~DiamondTrap( void );

        void            attack( const std::string& target );
        void            whoAmI( void ) const;

    private:
        // Intentionally shadows ClapTrap::_name per subject
        std::string     _name;
};

#endif
