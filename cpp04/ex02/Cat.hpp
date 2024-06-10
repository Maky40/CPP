/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:42:07 by mnie              #+#    #+#             */
/*   Updated: 2024/06/08 11:52:46 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private :
		Brain *_brain;

	public:
	// Constructors
		Cat();
		Cat(const Cat &copy);
	// Deconstructors
		~Cat();

	// Overloaded Operators
		Cat &operator=(const Cat &src);
		void	makeSound() const;

		Brain *getBrain(void) const;
};

#endif