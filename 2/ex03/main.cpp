/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-26 11:56:23 by bh                #+#    #+#             */
/*   Updated: 2025-10-26 11:56:23 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Point.hpp"

static void test_case(const char* title,
                      Point const a,
                      Point const b,
                      Point const c,
                      Point const p)
{
	std::cout << title << ": "
	          << (bsp(a, b, c, p) ? "inside" : "outside")
	          << std::endl;
}

int main(void)
{
	// Triangle ABC (scalene, non-degenerate)
	Point const A(0.0f, 0.0f);
	Point const B(5.0f, 0.0f);
	Point const C(2.0f, 4.0f);

	// Strictly inside
	Point const P1(2.0f, 1.0f);
	// Outside
	Point const P2(5.1f, 0.1f);
	// On edge AB (should be outside by spec)
	Point const P3(2.5f, 0.0f);
	// On vertex C (should be outside)
	Point const P4(2.0f, 4.0f);
	// Near an edge but inside (epsilon-ish)
	Point const P5(2.0f, 0.0039f);

	test_case("P1 (inside)",  A, B, C, P1);
	test_case("P2 (outside)", A, B, C, P2);
	test_case("P3 (on edge)", A, B, C, P3);
	test_case("P4 (vertex)",  A, B, C, P4);
	test_case("P5 (near edge, inside)", A, B, C, P5);

	return 0;
}
