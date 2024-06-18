/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:23:06 by mnie              #+#    #+#             */
/*   Updated: 2024/06/11 18:58:19 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const AAnimal *animal;
	animal = new AAnimal();

	const AAnimal *animal[20];

	for (int i = 0; i < 20; i++) {
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	for (size_t i = 0; i < 20; i++) {
		animal[i]->makeSound();
	}
	for (int i = 0; i < 20; i++)
		delete animal[i];

	Cat cat1;
	Cat cat2;

	cat1.getBrain()->setIdea(0, "Je mange des surmulots\n");
	cat2 = cat1;

	Dog dog1;
	Dog dog2;

	dog1.getBrain()->setIdea(0, "Je mange des croquettes\n");
	dog2 = dog1;

	return (0);
}
