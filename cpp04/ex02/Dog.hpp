/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:14:04 by mnie              #+#    #+#             */
/*   Updated: 2024/06/08 12:10:50 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
			Brain *_brain;
	public:
			Dog();
			Dog(Dog const &copy);
			Dog &operator=(Dog const &src);
			~Dog();
			void	makeSound() const;
			Brain *getBrain(void) const;
};

#endif