/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-31 09:08:09 by bh                #+#    #+#             */
/*   Updated: 2025-10-31 09:08:09 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class   AMateria;

class IMateriaSource
{
    public:

        virtual             ~IMateriaSource( void ) {}
        virtual void        learnMateria( AMateria* ) = 0;
        virtual AMateria*   createMateria( std::string const& type ) = 0;

};

#endif