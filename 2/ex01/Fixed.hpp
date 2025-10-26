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

# include <iosfwd>

class   Fixed
{
    public:

         Fixed( void );
         Fixed( const Fixed& original );
         Fixed& operator=( const Fixed& right_operand );
        ~Fixed( void) ;

        Fixed( const int value );
        Fixed( const float value );

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

    private:

        int                 _raw;
        static const int    _fracBits = 8;
};

std::ostream& operator<<(std::ostream& os, Fixed const& right_operand);

#endif