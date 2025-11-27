/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-27 11:43:31 by bh                #+#    #+#             */
/*   Updated: 2025-11-27 11:43:31 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try
    {
        Bureaucrat b("Bob", 149);
        std::cout << b << std::endl;

        b.decrementGrade();
        std::cout << b << std::endl;

        b.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "----" << std::endl;

    try
    {
        Bureaucrat c("Charlie", 200);
        std::cout << c << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
