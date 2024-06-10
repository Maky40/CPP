/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:47:06 by mnie              #+#    #+#             */
/*   Updated: 2024/06/04 14:04:58 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H
// Includes
#include "ClapTrap.hpp"

// classes

class ScavTrap: public ClapTrap
{
	private:
		bool _guarding_gate;
	public:
	// Constructors
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);

	// Deconstructors
		virtual ~ScavTrap();

	// Overloaded Operators
		ScavTrap &operator=(const ScavTrap &src);

	// Public Methods
		void attack(const std::string &target);
		void guardGate(void);
	// Getter

	// Setter

};

#endif