/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:16:40 by mnie              #+#    #+#             */
/*   Updated: 2024/06/11 18:53:52 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"){
	std::cout<<"Create a Dog derivate of AAnimal"<<std::endl;
	this->_brain = new Brain();
}
Dog::Dog(Dog const &copy) : AAnimal(copy.type){
	std::cout<<"Create a copy Dog derivate of AAnimal"<<std::endl;
	this->_brain = 0;
	*this = copy;
	return ;
}
Dog::~Dog(){
	std::cout<<"Kill a Dog derivate of AAnimal"<<std::endl;
	delete this->_brain;
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
		std::cout<<"OUAF"<<std::endl;
}
Brain *Dog::getBrain(void) const {
	return (this->_brain);
}