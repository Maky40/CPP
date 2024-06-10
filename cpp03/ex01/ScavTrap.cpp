/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:00:00 by mnie              #+#    #+#             */
/*   Updated: 2024/06/04 14:18:12 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"



// Constructors
ScavTrap::ScavTrap() : ClapTrap()
{
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
    this->_guarding_gate = false;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    this->_guarding_gate = copy._guarding_gate;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->setHP(100);
    this->setEP(50);
    this->setAD(20);
    this->_guarding_gate = false;
    std::cout << "ScavTrap Constructor for the name " << this->getName() << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstructor for " << this->getName() << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap Assignation operator called" << std::endl;
    this->setName(src.getName());
    this->setHP(src.getHP());
    this->setEP(src.getEP());
    this->setAD(src.getAD());
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->getEP() > 0 && this->getHP() > 0)
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAD() << " points of damage!" << std::endl;
        this->setEP(this->getEP() - 1);
    }
    else if (this->getEP() == 0)
        std::cout << "\033[31mScavTrap " << this->getName() << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
    else
        std::cout << "\033[31mScavTrap " << this->getName() << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
}

void ScavTrap::guardGate(void)
{
    if (this->_guarding_gate == false)
    {
        this->_guarding_gate = true;
        std::cout << "ScavTrap " << this->getName() << " is now guarding the gate." << std::endl;
    }
    else
        std::cout << "\033[33mScavTrap " << this->getName() << " is already guarding the gate.\033[0m" << std::endl;
}
