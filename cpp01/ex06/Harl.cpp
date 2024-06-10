/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:33:18 by mnie              #+#    #+#             */
/*   Updated: 2024/05/31 13:09:44 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}
void	Harl::debug()
{
	std::cout << "[ DEBUG ]\n"
		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		"I really do!" << std::endl;
	return ;
}

void	Harl::info()
{
	std::cout << "[ INFO ]\n"
		"I cannot believe adding extra bacon costs more money.\n"
		"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	return ;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]\n"
		"I think I deserve to have some extra bacon for free.\n"
		"I've been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\n"
		"This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	typedef void(Harl::*functionPointer)(void);

	functionPointer functionTab[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int cur_ft = -1;
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i]))
			cur_ft = i;
	}
	switch (cur_ft)
	{
		case 0:
			(this->*functionTab[0])();
		case 1:
			(this->*functionTab[1])();
		case 2:
			(this->*functionTab[2])();
		case 3:
			(this->*functionTab[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}