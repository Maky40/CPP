/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:45 by mnie              #+#    #+#             */
/*   Updated: 2024/07/06 16:34:50 by mnie             ###   ########.fr       */
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


// CONSTRUCTORS
Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{}
Bureaucrat::Bureaucrat(int grade) : _name("")
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else 
        this -> _grade = grade;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else 
        this -> _grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &src){
    *this = src;}

// DESTRUCTOR
Bureaucrat::~Bureaucrat()
{}

// GETTERS
std::string Bureaucrat::getName() const{
    return (this -> _name);}

int Bureaucrat::getGrade() const {
    return (this -> _grade);}

// MEMBER FUNCTION
void Bureaucrat::signForm(Form &_form)
{
    try {
        _form.beSigned( *this );
        std::cout << _name << " signed " << _form.getName() << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << _name << " coulnd't sign " << _form.getName() 
        << " because " << e.what() << std::endl;
    }
}

// INCREMENT AND DECREMENT
void verify_grade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
void Bureaucrat::increment()
{
    std::cout << "Incrementation of 1 (-1)" << std::endl;
    try {
        verify_grade(this->_grade - 1);
        this->_grade--;
    } catch (const GradeTooHighException& e) {
        std::cout << e.what();
    }
}
void Bureaucrat::decrement()
{
    std::cout << "Decrementation of 1 (+1)" << std::endl;
    try {
        verify_grade(this->_grade + 1);
        this->_grade++;
    } catch (const GradeTooLowException& e) {
        std::cout << e.what();
    }
}


// OVERLOARD OPERATORS AND STREAM
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return *this;

	this->_grade = src.getGrade();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a)
{
	o << a.getName()  << ", bureaucrat grade " << a.getGrade() << ".";
	return (o);
}