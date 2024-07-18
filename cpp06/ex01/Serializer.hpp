/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:51:31 by mnie              #+#    #+#             */
/*   Updated: 2024/07/16 13:09:00 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <string>
#include <stdint.h>

#define BLUE "\033[94m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

struct Data
{
	int 	int_nb;
	float	fl_nb;
};

class Serializer
{
	private:
	
	Serializer();
	Serializer(const Serializer &copy);
	Serializer& operator=(const Serializer &change);

	public:

	~Serializer();
	static uintptr_t serialize(Data* ptr);  /*unsigned integer type designed to store the entire address range*/
	static Data* deserialize(uintptr_t raw);
};
#endif