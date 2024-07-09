/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:48 by mnie              #+#    #+#             */
/*   Updated: 2024/07/07 15:20:38 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat dofus("dofus", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Bureaucrat Maignan("Maignan", 150);
		Maignan.decrement();
		std::cout << Maignan << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Bureaucrat MJ("MJ", 5);
		for(int i = 0; i < 5; i++)
		{
			MJ.increment();
			std::cout << MJ << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Form nuclear("Nuclear Code", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Bureaucrat gauth("gauthier", 26);
		std::cout << gauth << std::endl;
		Form nuclear("Nuclear Code", 1, 1);
		Form sausage("Sausage at lunch", 120, 120);
		std::cout << std::endl;
		std::cout << nuclear << std::endl;
		std::cout << std::endl;
		std::cout << sausage << std::endl;
		sausage.beSigned(gauth);
		gauth.signForm(sausage);
		std::cout << std::endl;
		std::cout << sausage << std::endl;
		std::cout << std::endl;
		gauth.signForm(nuclear);
		nuclear.beSigned(gauth);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	return (0);
}