/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:07:00 by mnie              #+#    #+#             */
/*   Updated: 2024/06/05 18:25:15 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain {
 private:
	std::string _ideas[100];

 public:
	// Constructors and destructors
	Brain(void); //NOLINT
	Brain(std::string const name); //NOLINT
	virtual ~Brain(void);

	// Copy constructor and assignation operator overload
	Brain(const Brain &src);
	Brain &operator=(const Brain &rhs);

	// Setters and getters
	std::string getIdea(int i) const;
	void setIdea(int i, std::string idea);
};

#endif