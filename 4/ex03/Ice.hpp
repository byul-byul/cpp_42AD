/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 08:48:28 by bh                #+#    #+#             */
/*   Updated: 2025-10-31 08:48:28 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class   Ice : public AMateria
{
    public:

                             Ice( void );
                             Ice( const Ice& original );
        Ice&           operator=( const Ice& right_operand );
        virtual             ~Ice( void );

        virtual AMateria*   clone( void ) const;
        virtual void        use( ICharacter& target );
};

#endif
