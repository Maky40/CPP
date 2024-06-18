/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:32:48 by mnie              #+#    #+#             */
/*   Updated: 2024/06/11 17:54:42 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():type("default")
{
	std::cout<<"Create an Animal default type"<<std::endl;
}
Animal::Animal(std::string type):type(type)
{
	std::cout<<"Create an Animal with type : "<<this->type<<std::endl;
}
Animal::Animal(const Animal &copy)
{
	std::cout<<"Create a copy Animal"<<std::endl;
	*this = copy;
	return ;
}
Animal::~Animal()
{
	std::cout<<"Kill an Animal"<<std::endl;
}
Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->type = src.type;
	return *this;
}
void	Animal::makeSound() const
{
	std::cout<<this->type<<" has no sound because it's not a cat or dog"<<std::endl;
}
std::string Animal::getType() const
{
	return (this->type);
}
