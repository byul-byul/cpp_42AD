/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 12:20:35 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 12:20:35 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class   WrongCat : public WrongAnimal
{
    public:

                         WrongCat( void );
                         WrongCat( const WrongCat& original );
                         WrongCat& operator=( const WrongCat& right_operand );
        virtual         ~WrongCat( void );

        void            makeSound( void ) const;
};

#endif