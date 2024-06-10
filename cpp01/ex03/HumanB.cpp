/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:24:47 by mnie              #+#    #+#             */
/*   Updated: 2024/05/30 18:01:25 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	this->weapon = NULL;
}

HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
}

void HumanB::attack()
{
	if (weapon) {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	} else {
		std::cout << name << " has no weapon to attack with" << std::endl;
	}
}