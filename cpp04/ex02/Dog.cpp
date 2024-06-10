/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:16:40 by mnie              #+#    #+#             */
/*   Updated: 2024/06/08 18:34:43 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"){
	std::cout<<"Create a Dog derivate of AAnimal"<<std::endl;
}
Dog::Dog(Dog const &copy) : AAnimal(copy.type){
	std::cout<<"Create a copy Dog derivate of AAnimal"<<std::endl;
	*this = copy;
	return ;
}
Dog::~Dog(){
	std::cout<<"Kill a Dog derivate of AAnimal"<<std::endl;
}
Dog &Dog::operator=(Dog const &src){
	if (this != &src)
	{
		this->type = src.type;
		delete this->_brain;
		this->_brain = new Brain(*src.getBrain());
	}
	return *this;
}
void	Dog::makeSound() const{
	if (this->type == "Dog")
		std::cout<<"OUAF"<<std::endl;
	else if (this->type == "Cat")
		std::cout<<"MIAOU"<<std::endl;
	else
		std::cout<<"Animal is not a cat or dog"<<std::endl;
}
Brain *Dog::getBrain(void) const {
	return (this->_brain);
}