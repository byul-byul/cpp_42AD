/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 12:09:38 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 12:09:38 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class   Dog : public Animal
{
    public:

                             Dog( void );
                             Dog( const Dog& original );
                             Dog& operator=( const Dog& right_operand );
        virtual             ~Dog( void );

        virtual void        makeSound( void ) const;
        const std::string&  getIdea( int idx ) const;
        void                setIdea( int idx, const std::string& idea );

    private:

        Brain*              _brain;
};

#endif