/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:13:00 by mnie              #+#    #+#             */
/*   Updated: 2024/05/31 16:32:27 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
	private:
			int RawBits;
			static const int nb_bits;
	public:
			Fixed();
			Fixed(Fixed const &src);
			~Fixed(void);
			int getRawBits( void ) const;
			void setRawBits( int const raw );
			Fixed &operator=(Fixed const &rhs);
};

#endif