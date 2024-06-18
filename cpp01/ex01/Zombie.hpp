/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:24:29 by mnie              #+#    #+#             */
/*   Updated: 2024/06/10 15:43:09 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	private:
			std::string name;
	public:
			Zombie();
			Zombie(std::string name);
			~Zombie();
			void announce();
			void setName(std::string name);
};
Zombie*	zombieHorde(int N, std::string name);

#endif