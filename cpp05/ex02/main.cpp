/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:48 by mnie              #+#    #+#             */
/*   Updated: 2024/07/08 09:52:43 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat louna("louna", 120);
		Bureaucrat max("max", 3);

		std::cout << "----------------------------------------------" << std::endl;
		AForm* a = new PresidentialPardonForm("thomas");
		AForm* b = new RobotomyRequestForm("thomas");
		AForm* c = new ShrubberyCreationForm("garden");

		std::cout << "----------------------------------------------" << std::endl;
		louna.signForm(*b);
		louna.signForm(*c);
		max.signForm(*b);
		louna.executeForm(*a);
		max.signForm(*a);
		louna.executeForm(*a);
		max.executeForm(*a);
		max.executeForm(*c);
		for(int i = 0; i < 5; i++)
			max.executeForm(*b);
		std::cout << "----------------------------------------------" << std::endl;
		delete a;
		delete b;
		delete c;	
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}