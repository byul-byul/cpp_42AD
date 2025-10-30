/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 10:30:20 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 10:30:20 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class   Animal
{
    public:

                             Animal( void );
                             Animal( const Animal& original );
                             Animal& operator=( const Animal& right_operand );
        virtual             ~Animal( void );

        virtual void        makeSound( void ) const;
        const std::string&  getType( void ) const;

    protected:

        std::string         type;
};

#endif