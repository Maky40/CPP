/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:46:42 by mnie              #+#    #+#             */
/*   Updated: 2024/07/08 11:47:10 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// constructors and destructor
Intern::Intern(){}
Intern::Intern(const Intern *copy){
    *this = copy;
}
Intern::~Intern(){}

// overloaded operator
Intern& Intern::operator=(const Intern &src){
    (void) src;
    return (*this);
}

// member function
static AForm *newShrubbery(const std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm *newRobotomy(const std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm *newPresidential(const std::string target) {
	return new PresidentialPardonForm(target);
}
AForm *Intern::makeForm(std::string const _name_aform, std::string const _target)
{
    AForm*  (*choosen_form[])(const std::string target) = {&newRobotomy, &newPresidential, &newShrubbery};
    
    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    for (int i = 0; i < 3; i++)
    {
        if (_name_aform == formNames[i])
        {
            std::cout<< GREEN << "Intern creates " << RESET << _name_aform << std::endl;
            return (choosen_form[i](_target));
        }
    }
    std::cerr   << RED  << "Name no corresponding about a task." 
                        << "Please write one of this three things :" 
                << BLUE << "\n- robotomy request"
                        << "\n- presidential pardon" 
                        << "\n- shrubbery creation" << RESET << std::endl;
    return NULL;
}