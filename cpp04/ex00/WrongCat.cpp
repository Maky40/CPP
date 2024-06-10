/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:44:44 by mnie              #+#    #+#             */
/*   Updated: 2024/06/05 14:46:49 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "call constructer form class WrongCat" << std::endl;
}
WrongCat::WrongCat(WrongCat &copy) : WrongAnimal()
{
	this->type = copy.type;
	std::cout << "call copy constructer from WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &copy)
{
	std::cout << "call operator from WrongCat" << std::endl;
	this->type = copy.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "call destructer from class WrongCat" << std::endl;
}
void WrongCat::makeSound() const
{
	std::cout << "WrongCat miaaaaaaaao" << std::endl;
}

std::string WrongCat::getType() const
{
	std::cout << "call getType from WrongCat" << std::endl;
	return this->type;
}