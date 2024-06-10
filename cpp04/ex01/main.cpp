/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:23:06 by mnie              #+#    #+#             */
/*   Updated: 2024/06/08 12:29:29 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal *animal1[20];
	Animal animal2;

	for (int i = 0; i < 20; i++) {
		if (i % 2 == 0)
			animal1[i] = new Dog();
		else
			animal1[i] = new Cat();
	}
	for (size_t i = 0; i < 20; i++) {
		animal1[i]->makeSound();
	}

	animal2 = *animal1[5];
	for (int i = 0; i < 20; i++) {
		delete animal1[i];
	}
	animal2.makeSound();
	Dog arial;
	arial.getBrain()->setIdea(0, "Je mange des croquettes");
	arial.getBrain()->setIdea(1, "Je fais des calins");
	std::cout << arial.getBrain()->getIdea(0) << std::endl;
	std::cout << arial.getBrain()->getIdea(1) << std::endl;

	// Dog dog; {   <-- for test during soutenance
	// 	 Dog tmp = dog;
	// }

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