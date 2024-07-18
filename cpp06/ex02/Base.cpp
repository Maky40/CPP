/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:14:05 by mnie              #+#    #+#             */
/*   Updated: 2024/07/16 17:32:09 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>


Base::~Base(){}

Base    *generate(void){
    std::srand(std::time(0));
    int index = rand() % 3;
    if (index == 0)
        return (new A);
    if (index == 1)
        return (new B);
    if (index == 2)    
        return (new C);
    return (NULL);
}
void    identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << GREEN << "This is an A object (PTR)" << RESET << std::endl;
	else if(dynamic_cast<B*>(p) != NULL)
		std::cout << GREEN << "This is a B object (PTR)" << RESET << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << GREEN << "This is a C object (PTR)" << RESET << std::endl;
	else
		std::cerr << RED << "This isn't an object A, B or C (PTR)" << RESET << std::endl;
}
void    identify(Base& p){
    try{
        A& obj = dynamic_cast<A&>(p);
        (void)obj;
        std::cout<<GREEN<<"It's a A Object (using reference)"<< RESET << std::endl;
        return ;
    }
    catch (...){}
    try
	{
		B& obj = dynamic_cast<B&>(p);
		(void)obj;
		std::cout << GREEN << "It's a B Object (using reference)" << RESET << std::endl;
		return ;
	}
	catch(...) {}

	try
	{
		C& obj = dynamic_cast<C&>(p);
		(void)obj;
		std::cout << GREEN << "It's a C Object (using reference)" << RESET << std::endl;
		return ;
	}
	catch(...) {}

	std::cerr << RED << "Que es amigo ?(reference)" << RESET << std::endl;
}