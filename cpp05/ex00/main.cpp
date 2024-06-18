/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:48 by mnie              #+#    #+#             */
/*   Updated: 2024/06/18 15:45:36 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 

int main()
{
    std::cout << RED << "\nTest Invalid Grade" << std::endl;
    try {
        Bureaucrat bureaucrat("ash", -1);
        std::cout << bureaucrat << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
     try {
        Bureaucrat bureaucrat("yo", 151);
        std::cout << bureaucrat << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << GREEN << "Test Increment with Grade at 2 (three times)" << std::endl;
    Bureaucrat artiste("l'artiste", 2);
    artiste.increment();
    artiste.increment();
    artiste.increment();
    std::cout << artiste;
    std::cout << YELLOW << "\nTest Decrement with Grade at 147 (four times)" << std::endl;
    Bureaucrat dofus("dofus temporis", 147);
    dofus.decrement();
    dofus.decrement();
    dofus.decrement();
    dofus.decrement();
    std::cout << dofus;
}