/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:45 by mnie              #+#    #+#             */
/*   Updated: 2024/07/07 18:20:48 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// CONSTRUCTORS
Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(int grade) : _name("") {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else 
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else 
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {}

// DESTRUCTOR
Bureaucrat::~Bureaucrat() {}

// GETTERS
std::string Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

// MEMBER FUNCTION
void Bureaucrat::signForm(AForm &_form) {
    try {
        _form.beSigned(*this);
        std::cout << _name << " signed " << _form.getName() << std::endl;
    } catch (AForm::GradeTooLowException &e) {
        std::cout << _name << " couldn't sign " << _form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
void Bureaucrat::executeForm(AForm const & form){
    try
	{
		form.execute(*this);
	}
	catch (std::exception & e) 
	{
		std::cerr << this->getName() << RED << " couldn’t execute " << 
			form.getName() << RED << " because " << e.what() << RESET << std::endl; 
	}
}

// INCREMENT AND DECREMENT
void Bureaucrat::increment() {
    std::cout << "Incrementation of 1 (-1)" << std::endl;
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrement() {
    std::cout << "Decrementation of 1 (+1)" << std::endl;
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

// OVERLOARD OPERATORS AND STREAM
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    if (this == &src)
        return *this;

    this->_grade = src.getGrade();
    return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &a) {
    o << a.getName()  << ", bureaucrat grade " << a.getGrade() << ".";
    return o;
}
