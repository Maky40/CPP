/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:39:27 by mnie              #+#    #+#             */
/*   Updated: 2024/05/30 15:40:22 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "HordeZombie");

	if (horde) {
		for (int i = 0; i < N; ++i) {
			horde[i].announce();
		}
		delete[] horde;  // Libération de la mémoire
	}

	return 0;
}