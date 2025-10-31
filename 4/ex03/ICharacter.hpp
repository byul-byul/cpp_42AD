/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 07:53:08 by bh                #+#    #+#             */
/*   Updated: 2025-10-31 07:53:08 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class   AMateria;

class   ICharacter
{
    public:

        virtual                     ~ICharacter( void ) {}
        virtual std::string const&  getName( void ) const = 0;
        virtual void                equip( AMateria* m ) = 0;
        virtual void                unequip( int idx ) = 0;
        virtual void                use( int idx, ICharacter& target ) = 0;

};

#endif