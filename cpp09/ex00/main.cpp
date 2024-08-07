/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:20:05 by mnie              #+#    #+#             */
/*   Updated: 2024/07/30 11:18:24 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isTxtExt(const std::string& filename) {
    std::string::size_type idx = filename.rfind('.');
    if (idx == std::string::npos || idx == 0) /*check if there is a '.' and if is not the first character*/
		return false;
	std::string extension = filename.substr(idx);
    if (extension != ".txt") /* check if after the '.' we have only "txt"*/
		return false;
	return true;
}

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error, we need two args : ./btc <filename>.txt");
		std::string filename = argv[1];
		if (!isTxtExt(filename))
			throw std::invalid_argument("Error, we need a .txt extension for the second arg");
		btc Bitcoin(filename);
		Bitcoin.init();
		Bitcoin.price_time();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}