/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:46:29 by mnie              #+#    #+#             */
/*   Updated: 2024/06/03 20:58:20 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), HP(10), EP(10), AD(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(std::string name): name(name), HP(10), EP(10), AD(0)
{
	std::cout << "ClapTrap Constructor for the name " << name << " called" << std::endl;
}

// Deconstructors
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor for " << name << " called" << std::endl;
}

// Overloaded Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->name = src.name;
	this->HP = src.HP;
	this->EP = src.EP;
	this->AD = src.AD;
	return *this;
}

// Public Methods
void	ClapTrap::attack(const std::string &target)
{
	if (this->EP > 0 && this->HP > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AD << " points of damage!" << std::endl;
		this->EP--;
	}
	else if (this->EP == 0)
		std::cout << "\033[31mClapTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left.\033[0m" << std::endl;
	else
		std::cout << "\033[31mClapTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points.\033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ( (unsigned int) this->HP > amount)
		this->HP -= amount;
	else if (this->HP > 0)
		this->HP = 0;
	else
	{
		std::cout << "\033[33mClapTrap " << this->name << " is already dead, stop beating it.\033[0m" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points, he now has " << this->HP << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EP > 0 && this->HP > 0 && this->HP + amount <= 10)
	{
		this->HP += amount;
		std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " of hit points, he now has " << this->HP << "hit points." << std::endl;
		this->EP--;
	}
	else if (this->EP == 0)
		std::cout << "\033[31mClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points.\033[0m" << std::endl;
	else if (this->HP == 0)
		std::cout << "\033[31mClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough hit points.\033[0m" << std::endl;
	else
		std::cout << "\033[33mClapTrap " << this->name << " can't be repaired to have more than 10 hit points.\033[0m" << std::endl;
}