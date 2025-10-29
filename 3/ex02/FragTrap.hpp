/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-28 16:29:56 by bh                #+#    #+#             */
/*   Updated: 2025-10-28 16:29:56 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class   FragTrap : public ClapTrap
{
    public:

                        FragTrap( void );
        explicit        FragTrap( const std::string& name );
                        FragTrap( const FragTrap& original );
                        FragTrap& operator=( const FragTrap& right_operand );
        virtual         ~FragTrap( void );

        void            attack( const std::string& target );
        void            highFivesGuys(void) const;
};

#endif