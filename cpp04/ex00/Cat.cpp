/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:46:06 by mnie              #+#    #+#             */
/*   Updated: 2024/06/05 18:05:23 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout<<"Create a Cat derivate of Animal"<<std::endl;
}
Cat::~Cat(){
	std::cout<<"Kill a Cat derivate of Animal"<<std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy.type){
	std::cout<<"Create a copy Cat derivate of Animal"<<std::endl;
	*this = copy;
	return ;
}
Cat &Cat::operator=(const Cat &src){
	if (this != &src)
		this->type = src.type;
	return *this;
}
void	Cat::makeSound() const{
	if (this->type == "Dog")
		std::cout<<"OUAF"<<std::endl;
	else if (this->type == "Cat")
		std::cout<<"MIAOU"<<std::endl;
	else
		std::cout<<"Animal is not a cat or dog"<<std::endl;
}