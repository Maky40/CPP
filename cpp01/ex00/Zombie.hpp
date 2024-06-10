/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:44:34 by mnie              #+#    #+#             */
/*   Updated: 2024/05/30 15:18:48 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
			std::string name;
	public:
			Zombie();
			Zombie(std::string name);
			~Zombie();
			void announce();
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif