/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 10:30:20 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 10:30:20 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class   AAnimal
{
    public:

                             AAnimal( void );
                             AAnimal( const AAnimal& original );
                             AAnimal& operator=( const AAnimal& right_operand );
        virtual             ~AAnimal( void );

        virtual void        makeSound( void ) const = 0;
        const std::string&  getType( void ) const;

    protected:

        std::string         type;
};

#endif