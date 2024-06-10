/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:13:00 by mnie              #+#    #+#             */
/*   Updated: 2024/06/10 21:36:04 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:

	int					_RawBits;
	static const int	nb_bits = 8;

	public:

	Fixed();
	Fixed(const int newInt);
	Fixed(const float newFloat);
	Fixed(const Fixed &copy);
	~Fixed();

	Fixed	&operator=(const Fixed &change);
	Fixed	operator+(const Fixed &change);
	Fixed	operator-(const Fixed &change);
	Fixed	operator*(const Fixed &change);
	Fixed	operator/(const Fixed &change);

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	bool operator<(const Fixed	&comp);
	bool operator>(const Fixed	&comp);
	bool operator<=(const Fixed	&comp);
	bool operator>=(const Fixed	&comp);
	bool operator==(const Fixed	&comp);
	bool operator!=(const Fixed	&comp);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed&	min(Fixed &a, Fixed &b);
	static Fixed const& min(Fixed const &a, Fixed const &b);
	static Fixed&	max(Fixed &a, Fixed &b);
	static Fixed const& max(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);

#endif