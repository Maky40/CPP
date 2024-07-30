/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:20:05 by mnie              #+#    #+#             */
/*   Updated: 2024/07/30 16:22:33 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error, we need two args : ./RPN <inverted polish>");
		rpn New;
		std::string polish = argv[1];
		New.execute(polish);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}