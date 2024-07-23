/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:14:10 by mnie              #+#    #+#             */
/*   Updated: 2024/07/23 11:30:49 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include "algorithm"
# include <cstdlib>

class Span{
    private :
    unsigned int _size_max;
    std::vector<int> vect;

    public :
    // constructors and destructor
    Span(unsigned int N);
    Span(const Span &src);
    ~Span();
    // member functions
    void addNumber(int nb);
    long int shortestSpan() const;
    long int longestSpan() const;
    void addMultiple(int (*f)(), unsigned int n);
    void printVectSort();
    // operator overloaded
    Span &operator=(const Span &src);
};
#endif