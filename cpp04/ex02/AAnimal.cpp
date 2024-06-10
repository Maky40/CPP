/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:32:48 by mnie              #+#    #+#             */
/*   Updated: 2024/06/08 11:52:16 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal():type("default")
{
	std::cout<<"Create an AAnimal default type"<<std::endl;
}
AAnimal::AAnimal(std::string type):type(type)
{
	std::cout<<"Create an AAnimal with type : "<<this->type<<std::endl;
}
AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout<<"Create a copy AAnimal"<<std::endl;
	*this = copy;
	return ;
}
AAnimal::~AAnimal()
{
	std::cout<<"Kill an AAnimal"<<std::endl;
}
AAnimal &AAnimal::operator=(const AAnimal &src){
	if (this != &src)
		this->type = src.type;
	return *this;
}
void	AAnimal::makeSound() const{
	std::cout<<this->type<<" has no sound because it's not a cat or dog"<<std::endl;
}
std::string AAnimal::getType() const{
	return (this->type);
}
