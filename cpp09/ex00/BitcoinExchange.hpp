/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:02:09 by mnie              #+#    #+#             */
/*   Updated: 2024/07/24 17:35:39 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include "algorithm"
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <cctype>
#include <limits>
#include <sstream>

class btc{

	private :
		std::map<std::string, double> data_csv;
		std::string _filename;
	public :
		// constructors and destructors
		btc(const std::string &filename);
		btc(const btc &src);
		~btc();
		// overloaded operator
		btc &operator=(const btc &copy);
		// member functions
		void init(const std::string& filename);
		void price_time(const btc &src);
		bool correct_format(const btc &src);
};


#endif