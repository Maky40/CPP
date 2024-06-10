/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:45:47 by mnie              #+#    #+#             */
/*   Updated: 2024/06/04 14:28:44 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap
{
	private:
			std::string name;
			int			HP;
			int			EP;
			int			AD;
	public:
			ClapTrap();
			ClapTrap(const ClapTrap &copy);
			ClapTrap(std::string name);
			~ClapTrap();
			ClapTrap &operator=(const ClapTrap &src);

			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);

			void setHP(int HP);
			void setEP(int EP);
			void setAD(int AD);
			void setName(std::string name);

			int getHP() const;
			int getEP() const;
			int getAD() const;
			std::string getName() const;
};

#endif