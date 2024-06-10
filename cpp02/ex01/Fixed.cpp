/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:09:13 by mnie              #+#    #+#             */
/*   Updated: 2024/06/03 15:30:56 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::nb_bits = 8;

Fixed::Fixed(void) : RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed(int const point) : RawBits(point << Fixed::nb_bits)
{
	std::cout << "Int constructor called" << std::endl;

	return;
}

Fixed::Fixed(float const point)
	: RawBits(roundf(point * (1 << Fixed::nb_bits)))
{
	std::cout << "Float constructor called" << std::endl;

	return;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

	return;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->RawBits = rhs.RawBits;

	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

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