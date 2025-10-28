/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-26 16:16:21 by bh                #+#    #+#             */
/*   Updated: 2025-10-26 16:16:21 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class   ClapTrap
{
    public:

                        ClapTrap( void );
        explicit        ClapTrap( const std::string& name );
                        ClapTrap( const ClapTrap& original );
                        ClapTrap& operator=( const ClapTrap& right_operand );
                        ~ClapTrap( void) ;

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