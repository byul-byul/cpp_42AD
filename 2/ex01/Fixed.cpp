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
# include <cmath>

Fixed::Fixed( void ): _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& original ) : _raw(0)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = original;
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

Fixed::Fixed( const int value )
{
    std::cout << "Int constructor called" << std::endl;
    this->_raw = value << _fracBits;
}

Fixed::Fixed( const float value )
{
    std::cout << "Float constructor called" << std::endl;
    this->_raw = static_cast<int>(roundf(value * (1 << _fracBits)));
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

float Fixed::toFloat() const
{
    return static_cast<float>(this->_raw) / static_cast<float>(1 << _fracBits);
}

int Fixed::toInt() const
{
    return this->_raw >> _fracBits;
}

std::ostream& operator<<(std::ostream& os, Fixed const& right_operand)
{
    return os << right_operand.toFloat();
}