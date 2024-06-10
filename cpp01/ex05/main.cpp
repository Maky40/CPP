/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:39:36 by mnie              #+#    #+#             */
/*   Updated: 2024/05/30 20:46:37 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Use: ./harl DEBUG" << std::endl
			<< "ou ./harl INFO" << std::endl
			<< "ou ./harl WARNING" << std::endl
			<< "ou ./harl ERROR" << std::endl;
		return (1);
	}

	Harl harl;
	harl.complain(argv[1]);
	return (0);
}