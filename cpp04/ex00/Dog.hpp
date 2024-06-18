/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:14:04 by mnie              #+#    #+#             */
/*   Updated: 2024/06/11 17:10:30 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
	private:

	public:
			Dog();
			Dog(Dog const &copy);
			Dog &operator=(Dog const &src);
			~Dog();
			void	makeSound() const;
};

#endif