/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:02:09 by mnie              #+#    #+#             */
/*   Updated: 2024/07/30 09:34:37 by mnie             ###   ########.fr       */
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
		void init();
		void price_time();
		void bitcoin_value(const std::string &date, const double &value);
};

// none members functions

bool valid_digit(const std::string& date, int start, int end);
bool check_date_format(const std::string& date);
bool get_file_date(const std::string& line);
double ft_stod(const std::string str);
bool check_value(const std::string& value);
double get_file_value(const std::string& line);
std::string get_csv_key(const std::string& line);
double get_csv_value(const std::string& line);

#endif