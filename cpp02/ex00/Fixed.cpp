/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:09:13 by mnie              #+#    #+#             */
/*   Updated: 2024/05/31 16:39:16 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::nb_bits = 8;

Fixed::Fixed() : RawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const &src)  /*: RawBits(src.RawBits)*/
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->RawBits = rhs.getRawBits();

	return *this;
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->RawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->RawBits = raw;

	return;
}