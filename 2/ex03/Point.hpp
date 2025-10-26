/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-26 14:05:00 by bh                #+#    #+#             */
/*   Updated: 2025-10-26 14:05:00 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class   Point
{
    public:

         Point( void );
         Point( const float x, const float y );
         Point( const Point& original );
         Point& operator=( const Point& right_operand );
        ~Point( void) ;

    private:

        const Fixed _x;
        const Fixed _y;
};

bool    bsp( Point const a, Point const b, Point const c, Point const point);

#endif