/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:02:44 by mnie              #+#    #+#             */
/*   Updated: 2024/07/07 17:33:45 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// constructors and destrucor
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : 
	AForm(copy) {}

PresidentialPardonForm::~PresidentialPardonForm(){}
// Overloaded operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &change)
{
	AForm::operator=(change);
	return (*this);
}
// member function
void	PresidentialPardonForm::action() const
{
	std::cout << this->_target << BLUE << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}