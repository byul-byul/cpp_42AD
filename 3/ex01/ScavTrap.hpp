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

class   SvavTrap
{
    public:

                        SvavTrap( void );
        explicit        SvavTrap( const std::string& name );
                        SvavTrap( const SvavTrap& original );
                        SvavTrap& operator=( const SvavTrap& right_operand );
                        ~SvavTrap( void) ;

        void            attack( const std::string& target);
        void            takeDamage( unsigned int amount );
        void            beRepaired( unsigned int amount );

    private:

        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;

        bool            _hasHitPoints( void ) const;
        bool            _hasEnergyPoints( void ) const;
        bool            _isActive( void ) const;
};

#endif