/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 12:20:35 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 12:20:35 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class   Cat : public Animal
{
    public:

                         Cat( void );
                         Cat( const Cat& original );
                         Cat& operator=( const Cat& right_operand );
        virtual         ~Cat( void );

        virtual void    makeSound( void ) const;
};

#endif