/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:11:52 by mnie              #+#    #+#             */
/*   Updated: 2024/06/04 15:30:01 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
this->setAD(30);
this->setEP(100);
this->setHP(100);
std::cout << "FragTrap Default Constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name): ClapTrap(name){
this->setAD(30);
this->setEP(100);
this->setHP(100);
std::cout << "FragTrap Constructor for the name " << this->getName() << " called" << std::endl;
}
FragTrap::~FragTrap(){
std::cout << "FragTrap Deconstructor for " << this->getName() << " called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &src){
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->setName(src.getName());
    this->setHP(src.getHP());
    this->setEP(src.getEP());
    this->setAD(src.getAD());
    return *this;
}
}
void FragTrap::highFiveGuys(void){
std::cout << "FragTrap " << this->getName() << ": You want a high five?\n\t*WHAMM*\nHere you go." << std::endl;
}