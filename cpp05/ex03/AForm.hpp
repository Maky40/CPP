/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:48:34 by mnie              #+#    #+#             */
/*   Updated: 2024/07/07 15:12:57 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <fstream>

#define BLUE "\033[94m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class Bureaucrat;  // Forward declaration de Bureaucrat

class AForm {

    private :
    std::string const   _name;
    bool                _signed;
    const int           _sign_grade;
    const int           _exec_grade;

    public :
    // constructors and deconstructor
    AForm();
    AForm(const AForm &src);
    AForm(std::string name);
    AForm(int sign_grade, int exec_grade);
    AForm(std::string name, int sign_grade, int exec_grade);
    virtual ~AForm();

    // Overloaded Operators 
    AForm &operator=(const AForm &src);

    // Getters
    const std::string getName(void)const;
    bool getSigned(void)const;
    int getSignGrade(void)const;
    int getExecGrade(void)const;

    // Member function
    void beSigned(Bureaucrat &b);
    void	execute(Bureaucrat const& executor) const;
    virtual void action() const = 0;

    // Exceptions
    class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("AForm grade is too High kopain\n");
            }
    };

    class GradeTooLowException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("AForm grade is too Low kopain\n");
            }
    };
     class UnsignedException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("AForm is unsigned kopain\n");
            }
    };
};

// Overloaded ostream
std::ostream &operator<<(std::ostream &o, AForm &a);

#endif
