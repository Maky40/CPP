/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:46:06 by mnie              #+#    #+#             */
/*   Updated: 2024/06/05 18:11:57 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout<<"Create a Cat derivate of Animal"<<std::endl;
	this->_brain = new Brain();
}
Cat::~Cat(){
	std::cout<<"Kill a Cat derivate of Animal"<<std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat &copy) : Animal(copy.type){
	std::cout<<"Create a copy Cat derivate of Animal"<<std::endl;
	this->_brain = 0;
	*this = copy;
	return ;
}
Cat &Cat::operator=(const Cat &src){
	if (this != &src)
	{
		this->type = src.type;
		delete this->_brain;
		this->_brain = new Brain(*src.getBrain());
	}
	return *this;
}
void	Cat::makeSound() const{
	std::cout<<"MIAOU"<<std::endl;
}
Brain *Cat::getBrain(void) const {
	return (this->_brain);
}