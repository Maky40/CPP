/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:05:04 by mnie              #+#    #+#             */
/*   Updated: 2024/07/06 16:22:06 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// CONSTRUCTORS AND DESTRUCTOR
Form::Form():_name("default"), _sign_grade(150), _exec_grade(150), _signed(false) 
{}
Form::Form(const Form &src) : _name(src._name), _signed(src._signed),
	_sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{}
Form::Form(std::string name): _name(name), _signed(false), _sign_grade(150), _exec_grade(150) 
{}
Form::Form(int sign_grade, int exec_grade) : _name("default"), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw Form::GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw Form::GradeTooLowException();
}
Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw Form::GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw Form::GradeTooLowException();
}
Form::~Form()
{}

// GETTERS
const std::string Form::getName(void)const{
    return (this->_name);
}
bool Form::getSigned(void)const{
    return (this->_signed);
}
int Form::getSignGrade(void)const{
    return (this->_sign_grade);
}
int Form::getExecGrade(void)const{
    return (this->_exec_grade);
}

// MEMBER FUNCTION
void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

//  OVERLOARD OPERATORS AND STEAM
Form &Form::operator=(const Form &src)
{
	if (this == &src)
		return *this;
	this->_signed = src._signed;
    return *this; /*nothing to assign after _signed because all is const*/
}

std::ostream	&operator<<(std::ostream &o, Form &a)
{
    std::string form_signed;

    if (a.getSigned())
        form_signed = "True";
    else 
        form_signed = "False";
    o << a.getName() << ": \nsigned is :"<< form_signed << ", cons grade required to sign it "
    << a.getSignGrade() << ", const grade required to execute it " << a.getExecGrade(); 
}