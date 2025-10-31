/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 08:46:07 by bh                #+#    #+#             */
/*   Updated: 2025/10/31 16:14:48 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class   Character : public ICharacter
{
    public:

                                     Character( void );
                                     Character( const std::string& name );
                                     Character( const Character& original );
        Character&                   operator=( const Character& right_operand );
        virtual                     ~Character( void );

        virtual std::string const&  getName( void ) const;
        virtual void                equip( AMateria* m );
        virtual void                unequip( int idx );
        virtual void                use( int idx, ICharacter& target );

    private:

        std::string                 _name;
        AMateria*                   _inventory[4];

        void                        _clearInventory( void );
        void                        _deepCopyFrom( const Character& other );
};

#endif
