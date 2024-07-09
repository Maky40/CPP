/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:05:04 by mnie              #+#    #+#             */
/*   Updated: 2024/07/07 16:02:44 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTOR
AForm::AForm() : _name("default"), _signed(false), _sign_grade(150), _exec_grade(150) {}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade) {}

AForm::AForm(std::string name) : _name(name), _signed(false), _sign_grade(150), _exec_grade(150) {}

AForm::AForm(int sign_grade, int exec_grade) : _name("default"), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
    if (sign_grade < 1 || exec_grade < 1)
        throw AForm::GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw AForm::GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw AForm::GradeTooLowException();
}
AForm::~AForm()
{}

// GETTERS
const std::string AForm::getName(void)const{
    return (this->_name);
}
bool AForm::getSigned(void)const{
    return (this->_signed);
}
int AForm::getSignGrade(void)const{
    return (this->_sign_grade);
}
int AForm::getExecGrade(void)const{
    return (this->_exec_grade);
}

// MEMBER FUNCTION
void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_sign_grade)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
		throw UnsignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	else
	{
		this->action();
		std::cout << BLUE << executor.getName() << YELLOW << " executed " << BLUE <<
			this->getName() << RESET << std::endl;
	}
}

//  OVERLOARD OPERATORS AND STEAM
AForm &AForm::operator=(const AForm &src)
{
	if (this == &src)
		return *this;
	this->_signed = src._signed;
    return *this; /*nothing to assign after _signed because all is const*/
}

std::ostream	&operator<<(std::ostream &o, AForm &a)
{
    std::string AForm_signed;

    if (a.getSigned())
        AForm_signed = "True";
    else 
        AForm_signed = "False";
    
    o << a.getName() << ": \nsigned is : "<< AForm_signed << ", cons grade required to sign it "
    << a.getSignGrade() << ", const grade required to execute it " << a.getExecGrade();
    return o;
}