/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:45:47 by mnie              #+#    #+#             */
/*   Updated: 2024/06/03 17:42:49 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

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
};

#endif