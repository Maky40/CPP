/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:16:40 by mnie              #+#    #+#             */
/*   Updated: 2024/06/11 17:15:22 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout<<"Create a Dog derivate of Animal"<<std::endl;
}
Dog::Dog(Dog const &copy) : Animal(copy.type){
	std::cout<<"Create a copy Dog derivate of Animal"<<std::endl;
	*this = copy;
	return ;
}
Dog::~Dog(){
	std::cout<<"Kill a Dog derivate of Animal"<<std::endl;
}
Dog &Dog::operator=(Dog const &src){
	if (this != &src)
		this->type = src.type;
	return *this;
}
void	Dog::makeSound() const{
	std::cout<<"OUAF"<<std::endl;
}