/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:23:19 by mnie              #+#    #+#             */
/*   Updated: 2024/06/05 14:37:16 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
	protected:
			std::string type;

	public:
			Animal();
			Animal(const Animal &copy);
			Animal(std::string type);
			virtual ~Animal();

			Animal &operator=(const Animal &src);
			virtual void	makeSound() const;

			std::string getType() const;
};

#endif