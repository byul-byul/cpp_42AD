/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-30 10:30:20 by bh                #+#    #+#             */
/*   Updated: 2025-10-30 10:30:20 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class   WrongAnimal
{
    public:

                            WrongAnimal( void );
                            WrongAnimal( const WrongAnimal& original );
                            WrongAnimal& operator=( const WrongAnimal& right_operand );
        virtual             ~WrongAnimal( void );

        void                makeSound( void ) const;
        const std::string&  getType( void ) const;

    protected:

        std::string         type;
};

#endif