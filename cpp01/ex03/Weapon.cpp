/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:48 by mnie              #+#    #+#             */
/*   Updated: 2024/05/30 18:09:17 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type)
{
}

Weapon::~Weapon(){}

const std::string& Weapon::getType() const {
	return type;
}

void Weapon::setType(const std::string& newType) {
	type = newType;
}