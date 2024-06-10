/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:08:30 by mnie              #+#    #+#             */
/*   Updated: 2024/06/05 18:10:37 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
	return;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
	return;
}

Brain::Brain(const Brain &src) {
	*this = src;
	return;
}

Brain &Brain::operator=(const Brain &rhs) {
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

std::string Brain::getIdea(int i) const {
	if (i < 0 || i > 99)
		return ("");
	return (this->_ideas[i]);
}

void Brain::setIdea(int i, std::string idea) {
	if (i < 0 || i > 99)
		return;
	this->_ideas[i] = idea;
}
