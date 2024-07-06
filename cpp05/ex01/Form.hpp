/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:48:34 by mnie              #+#    #+#             */
/*   Updated: 2024/07/06 16:22:06 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form {

    private :
    std::string const   _name;
    bool                _signed;
    const int           _sign_grade;
	const int           _exec_grade;

    public :

    // constructors and deconstructor
    Form();
    Form(const Form &src);
    Form(std::string name);
    Form(int sign_grade, int exec_grade);
    Form(std::string name, int sign_grade, int exec_grade);
    ~Form();

    // Overloaded Operators 
    Form &operator=(const Form &src);

    // Getters
    const std::string getName(void)const;
	bool getSigned(void)const;
	int getSignGrade(void)const;
	int getExecGrade(void)const;

    // Member function
    void beSigned(Bureaucrat &b);

    // Exceptions
    class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw()
            {
                return ("Form grade is too High kopain\n");
            }
        };

	class GradeTooLowException : public std::exception {
        public :
            virtual const char* what() const throw()
            {
                return ("Form grade is too Low kopain\n");
            }
        };
};
// Overloaded ostream
    std::ostream	&operator<<(std::ostream &o, Form &a);
#endif