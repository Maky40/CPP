/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:51 by mnie              #+#    #+#             */
/*   Updated: 2024/06/17 17:52:24 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>

#define BLUE "\033[94m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class Bureaucrat {
    
    private :
    std::string const   name;
    int                 grade;
    
    public :
    Bureaucrat(std::string const name, int grade);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void increment();
    void decrement();
    
    // exceptions
    class GradeTooHighException : public std::exception {
        public :
            virtual const char* what() const throw()
            {
                return ("Grade is too High kopain\n");
            }
        };

	class GradeTooLowException : public std::exception {
        public :
            virtual const char* what() const throw()
            {
                return ("Grade is too Low kopain\n");
            }
        };
    friend std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

};
#endif