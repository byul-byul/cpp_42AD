/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-26 14:05:03 by bh                #+#    #+#             */
/*   Updated: 2025-10-26 14:05:03 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point( void ):
    _x(0),
    _y(0)
    {}

Point::Point( const float x, const float y ):
    _x(x),
    _y(y)
    {}

Point::Point( const Point& original ):
    _x(original._x),
    _y(original._y)
    {}

Point& Point::operator=( const Point& right_operand )
{
	(void)right_operand;
	return *this;
}

Point::~Point( void ) {}

const Fixed&	Point::getX( void ) const { return _x; }
const Fixed&	Point::getY( void ) const { return _y; }
