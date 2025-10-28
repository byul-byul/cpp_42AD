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

bool Fixed::operator>(const Fixed& right_operand) const  { return _raw >  right_operand._raw; }
bool Fixed::operator<(const Fixed& right_operand) const  { return _raw <  right_operand._raw; }
bool Fixed::operator>=(const Fixed& right_operand) const { return _raw >= right_operand._raw; }
bool Fixed::operator<=(const Fixed& right_operand) const { return _raw <= right_operand._raw; }
bool Fixed::operator==(const Fixed& right_operand) const { return _raw == right_operand._raw; }
bool Fixed::operator!=(const Fixed& right_operand) const { return _raw != right_operand._raw; }

Fixed Fixed::operator+(const Fixed& right_operand) const
{
    Fixed out;
    out._raw = this->_raw + right_operand._raw;
    return out;
}

Fixed Fixed::operator-(const Fixed& right_operand) const
{
    Fixed out;
    out._raw = this->_raw - right_operand._raw;
    return out;
}

Fixed Fixed::operator*(const Fixed& right_operand) const
{
    Fixed out;
    const long long a = static_cast<long long>(this->_raw);
    const long long b = static_cast<long long>(right_operand._raw);
    out._raw = static_cast<int>((a * b) >> _fracBits);
    return out;
}

Fixed Fixed::operator/(const Fixed& right_operand) const
{
    Fixed out;
    const long long a = static_cast<long long>(this->_raw) << _fracBits;
    const long long b = static_cast<long long>(right_operand._raw);
    out._raw = static_cast<int>(a / b);
    return out;
}

Fixed& Fixed::operator++()
{
    ++_raw;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++_raw;
    return tmp;
}

Fixed& Fixed::operator--()
{
    --_raw;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --_raw;
    return tmp;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_raw = raw;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

float   Fixed::toFloat() const { return static_cast<float>(this->_raw) / static_cast<float>(1 << _fracBits); }
int     Fixed::toInt() const { return this->_raw >> _fracBits; }

std::ostream& operator<<(std::ostream& os, Fixed const& right_operand) { return os << right_operand.toFloat(); }