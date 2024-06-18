/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:45 by mnie              #+#    #+#             */
/*   Updated: 2024/06/18 15:30:12 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
// {
// 	return ("Grade is too high");
// }

// const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
// {
// 	return ("Grade is too low");
// }

void verify_grade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::~Bureaucrat()
{}
std::string Bureaucrat::getName() const
{
    return (this -> name);
}
int 
Bureaucrat::getGrade() const 
{
    return (this -> grade);
}

void Bureaucrat::increment()
{
    std::cout << "Incrementation of 1 (-1)" << std::endl;
    try {
        verify_grade(this->grade - 1);
        this->grade--;
    } catch (const GradeTooHighException& e) {
        std::cout << e.what();
    }
}
void Bureaucrat::decrement()
{
    std::cout << "Decrementation of 1 (+1)" << std::endl;
    try {
        verify_grade(this->grade + 1);
        this->grade++;
    } catch (const GradeTooLowException& e) {
        std::cout << e.what();
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}