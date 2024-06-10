/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:33:18 by mnie              #+#    #+#             */
/*   Updated: 2024/05/31 13:08:18 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}
void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		"I really do!" << std::endl;
	return ;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
		"You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	return ;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
		"I've been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	typedef void(Harl::*functionPointer)(void);

	functionPointer functionTab[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4)
	{
		if (!level.compare(levels[i]))
		{
			(this->*functionTab[i])();
			exit(0);
		}
		i++;
	}
	if (i == 4)
	{
		std::cerr << "Error: incorrect selection" << std::endl;
		exit(1);
	}
}