/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-26 11:09:07 by bh                #+#    #+#             */
/*   Updated: 2025-10-26 11:09:07 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class   Fixed
{
    public:

         Fixed( void );
         Fixed( const Fixed& original );
         Fixed& operator=( const Fixed& right_operand );
        ~Fixed( void) ;

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

    private:

        int                 _raw;
        static const int    _fracBits = 8;
};

#endif