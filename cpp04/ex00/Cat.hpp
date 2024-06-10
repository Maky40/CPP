/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:42:07 by mnie              #+#    #+#             */
/*   Updated: 2024/06/05 14:16:42 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
	private :

	public:
	// Constructors
		Cat();
		Cat(const Cat &copy);
	// Deconstructors
		~Cat();

	// Overloaded Operators
		Cat &operator=(const Cat &src);
		void	makeSound() const;
};

#endif