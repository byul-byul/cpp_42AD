/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 08:48:31 by bh                #+#    #+#             */
/*   Updated: 2025-10-31 08:48:31 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class   Cure : public AMateria
{
    public:

                             Cure( void );
                             Cure( const Cure& original );
        Cure&           operator=( const Cure& right_operand );
        virtual             ~Cure( void );

        virtual AMateria*   clone( void ) const;
        virtual void        use( ICharacter& target );
};

#endif
