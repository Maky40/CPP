/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:43:50 by mnie              #+#    #+#             */
/*   Updated: 2024/06/05 14:44:05 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "WrongAnimal";
    std::cout << "call constructer of WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "call destructer of WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &copy)
{
    this->type = copy.type;
    std::cout << "call copy constructer of WrongAnimal" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "print sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    std::cout << "call getType from WrongAnimal" << std::endl;
    return this->type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
    this->type = copy.type;
    std::cout << "call operator= of WrongAnimal" << std::endl;
    return *this;
}
