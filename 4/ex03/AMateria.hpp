/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 06:02:18 by bh                #+#    #+#             */
/*   Updated: 2025/10/31 16:13:57 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class   ICharacter;

class   AMateria
{
    public:

                             AMateria( const std::string& type );
                             AMateria( const AMateria& original );
        AMateria&           operator=( const AMateria& right_operand );
        virtual             ~AMateria( void );

        std::string const&  getType( void ) const; //Returns the materia type
        virtual AMateria*   clone( void ) const = 0;
        virtual void        use( ICharacter& target );

    protected:

                             AMateria( void );
        std::string         type;
};

#endif