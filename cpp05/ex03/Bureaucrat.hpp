/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:51 by mnie              #+#    #+#             */
/*   Updated: 2024/07/07 17:45:57 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <stdexcept>

#define BLUE "\033[94m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class AForm;

class Bureaucrat {

    private :
    std::string const   _name;
    int                 _grade;

    public :
    // constructors and destructor
    Bureaucrat();
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat(int grade);
    Bureaucrat(const std::string name);
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat();

    // Overloaded operator
    Bureaucrat &operator=(const Bureaucrat &src);

    // Getters
    std::string getName() const;
    int getGrade() const;

    // Member function
    void signForm(AForm &_form);
    void executeForm(AForm const & form);

    // Increment et decrement functions
    void increment();
    void decrement();

    // exceptions
    class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("Grade is too High kopain\n");
            }
    };

    class GradeTooLowException : public std::exception {
        public :
            virtual const char* what() const throw() {
                return ("Grade is too Low kopain\n");
            }
    };
};

// Overloaded ostream
std::ostream &operator<<(std::ostream &o, Bureaucrat &a);

#endif
