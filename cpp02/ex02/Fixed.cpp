/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:09:13 by mnie              #+#    #+#             */
/*   Updated: 2024/06/03 15:31:54 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::nb_bits = 8;

Fixed::Fixed(void) : RawBits(0)
{
	return;
}

Fixed::Fixed(int const point) : RawBits(point << Fixed::nb_bits)
{
	return;
}

Fixed::Fixed(float const point)
	: RawBits(roundf(point * (1 << Fixed::nb_bits)))
{
	return;
}

Fixed::Fixed(Fixed const &src) : RawBits(src.RawBits)
{
	return;
}

Fixed::~Fixed(void)
{
	return;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->RawBits = rhs.RawBits;

	return *this;
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return this->RawBits > rhs.RawBits;
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return rhs > *this;
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return !(*this < rhs);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return !(*this > rhs);
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return this->RawBits == rhs.RawBits;
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return !(*this == rhs);
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed res;

	res.RawBits = this->RawBits + rhs.RawBits;

	return res;
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed res;

	res.RawBits = this->RawBits - rhs.RawBits;

	return res;
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void)
{
	++this->RawBits;

	return *this;
}

Fixed &Fixed::operator--(void)
{
	--this->RawBits;

	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed prev(*this);

	++*this;

	return prev;
}

Fixed Fixed::operator--(int)
{
	Fixed prev(*this);

	--*this;

	return prev;
}

Fixed const &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return Fixed::min(const_cast<Fixed const &>(lhs), rhs);
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	return lhs > rhs ? rhs : lhs;
}

Fixed const &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return Fixed::max(const_cast<Fixed const &>(lhs), rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	return rhs > lhs ? rhs : lhs;
}

int Fixed::getRawBits(void) const
{
	return this->RawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->RawBits = raw;

	return;
}

float Fixed::toFloat(void) const
{
	return this->RawBits / static_cast<float>(1 << Fixed::nb_bits);
}

int Fixed::toInt(void) const
{
	return this->RawBits >> Fixed::nb_bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();

	return o;
}