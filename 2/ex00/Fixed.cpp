/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bh <bh@student.42.fr>                      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-26 11:46:43 by bh                #+#    #+#             */
/*   Updated: 2025-10-26 11:46:43 by bh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

Fixed::Fixed( void ): _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& original ): _raw(original._raw)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& right_operand)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &right_operand)
        this->_raw = right_operand._raw;
    return *this;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_raw = raw;
}
