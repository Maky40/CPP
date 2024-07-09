/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:49:53 by mnie              #+#    #+#             */
/*   Updated: 2024/07/08 11:12:11 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// constructors and destructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << GREEN << "Constructor " << BLUE << " RobotomyRequestForm " <<
		GREEN << "called." << " Target is : " << BLUE << target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : 
	AForm(copy) {}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREEN << "Destructor " << BLUE << " RobotomyRequestForm " <<
		GREEN << "called." << RESET << std::endl;
}

// overloaded operation
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &change)
{
	AForm::operator=(change);
	return (*this);
}
// member function
void	RobotomyRequestForm::action() const
{
	std::cout << YELLOW << "Boum Boum DRILLLLLLL BOUM BOUM" << RESET<< std::endl;
	int random_number = rand();
	if (random_number % 2 == 0)
		std::cout << BLUE << this->_target << YELLOW << " has been robotomized succesfully." << RESET << std::endl;
	else
		std::cout << YELLOW << "Robotomy failed" << RESET << std::endl;
}