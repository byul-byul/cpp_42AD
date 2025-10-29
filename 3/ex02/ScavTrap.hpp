/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-28 16:29:56 by bh                #+#    #+#             */
/*   Updated: 2025-10-28 16:29:56 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap
{
    public:

                        ScavTrap( void );
        explicit        ScavTrap( const std::string& name );
                        ScavTrap( const ScavTrap& original );
                        ScavTrap& operator=( const ScavTrap& right_operand );
        virtual         ~ScavTrap( void );

        void            attack( const std::string& target );
        void            guardGate( void ) const;
};

#endif