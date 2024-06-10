/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:23:19 by mnie              #+#    #+#             */
/*   Updated: 2024/06/08 11:51:30 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>
#include <string>

class AAnimal
{
	protected:
			std::string type;

	public:
			AAnimal();
			AAnimal(const AAnimal &copy);
			AAnimal(std::string type);
			virtual ~AAnimal();

			AAnimal &operator=(const AAnimal &src);
			virtual void	makeSound() const = 0;

			std::string getType() const;
};

#endif