/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 09:12:50 by bh                #+#    #+#             */
/*   Updated: 2025/10/31 16:12:58 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class   MateriaSource : public IMateriaSource
{
    public:

                             MateriaSource( void );
                             MateriaSource( const MateriaSource& original );
        MateriaSource&           operator=( const MateriaSource& right_operand );
        virtual             ~MateriaSource( void );

        virtual void        learnMateria( AMateria* m );
        virtual AMateria*   createMateria( std::string const& type );

    private:

        AMateria*           _storage[4];

        void                _clearStorage( void );
        void                _deepCopyFrom( const MateriaSource& other );
};

#endif
