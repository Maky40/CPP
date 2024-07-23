/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:52:36 by mnie              #+#    #+#             */
/*   Updated: 2024/07/23 11:46:54 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// constructors and destructor
Span::Span(unsigned int N) : _size_max(N){
    this -> vect.reserve(N);
}
Span::Span(const Span &src){
    *this = src;
}
Span::~Span(){
}
    // member functions
void Span::addNumber(int nb){
    if (vect.size() >= _size_max)
        throw std::out_of_range("Span is full");
    vect.push_back(nb);
}
void	Span::addMultiple(int(*f)(void), unsigned int n)
{
	if (this->vect.size() + n > this->_size_max)
		throw std::out_of_range("Not enought numbers");
	for (unsigned int i = 0; i < n; i++)
		this->vect.push_back(f());
}
long int Span::shortestSpan()const{
    if (vect.size() < 2)
        throw std::out_of_range("Not enought numbers");
    std::vector<int> sorted_vect = vect;
    std::sort(sorted_vect.begin(), sorted_vect.end());
    long int min = abs(vect[0] - vect[1]);
    for (std::vector<int>::iterator it = sorted_vect.begin() + 1; it != sorted_vect.end(); it++)
    {
        if (min > abs(*it - *(it - 1)))
            min = abs(*it - *(it - 1));
    }
    return (min);
}
long int Span::longestSpan() const{
    if (vect.size() < 2)
        throw std::out_of_range("Not enought numbers");
    return (*(std::max_element(vect.begin(), vect.end())) - *(std::min_element(vect.begin(), vect.end())));        
}

void Span::printVectSort(){
    std::vector<int> sorted_vector = vect;
    std::sort(sorted_vector.begin(), sorted_vector.end());
    for(std::vector<int>::iterator it = sorted_vector.begin(); it != sorted_vector.end(); it++)
    {
        std::cout<<"| "<< *it << " ";
    }
    std::cout   <<"\n\n\n";
    std::cout   <<"Max number: "
                << *(std::max_element(sorted_vector.begin(), sorted_vector.end()))
                <<"\nMin number: "
                << *(std::min_element(sorted_vector.begin(), sorted_vector.end()))
                << std::endl;
}
    // operator overloaded
Span &Span::operator=(const Span &src){
    if (this != &src){
        this -> _size_max = src._size_max;
        this -> vect = src.vect;
    }
    return (*this);
}