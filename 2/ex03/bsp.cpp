/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-28 12:44:58 by bh                #+#    #+#             */
/*   Updated: 2025-10-28 12:44:58 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

// Cross product (2D z-component) of (Q - P) x (R - P)
static Fixed cross(const Point& P, const Point& Q, const Point& R)
{
	const Fixed x1 = Q.getX() - P.getX();
	const Fixed y1 = Q.getY() - P.getY();
	const Fixed x2 = R.getX() - P.getX();
	const Fixed y2 = R.getY() - P.getY();
	return x1 * y2 - y1 * x2;
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	// Optional: reject degenerate triangles
	if (cross(a, b, c) == Fixed(0)) return false;

	const Fixed s1 = cross(a, b, point);
	const Fixed s2 = cross(b, c, point);
	const Fixed s3 = cross(c, a, point);

	// On edge or vertex -> false (strictly inside only)
	if (s1 == Fixed(0) || s2 == Fixed(0) || s3 == Fixed(0))
		return false;

	const bool all_pos = (s1 > Fixed(0)) && (s2 > Fixed(0)) && (s3 > Fixed(0));
	const bool all_neg = (s1 < Fixed(0)) && (s2 < Fixed(0)) && (s3 < Fixed(0));
	return all_pos || all_neg;
}
