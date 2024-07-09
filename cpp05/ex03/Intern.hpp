/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:35:54 by mnie              #+#    #+#             */
/*   Updated: 2024/07/08 10:44:40 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private : 
    
    public :
    // constructors and destructor
    Intern();
    Intern(const Intern *copy);
    ~Intern();
    // Overloaded operator
    Intern &operator=(const Intern &src);
    // member function
    AForm *makeForm(std::string const _name_aform, std::string const _target);
};
#endif