/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:02:00 by mnie              #+#    #+#             */
/*   Updated: 2024/07/24 18:43:31 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// constructors and destructors
btc::btc(const std::string &filename): _filename(filename)
{}
btc::btc(const btc &src){
	*this = src;
}
btc::~btc(){

}
// overloaded operator
btc &btc::operator=(const btc &copy) {
	if (this != &copy)
	{
		this -> _filename = copy._filename;
		this -> data_csv = copy.data_csv;
	}
	return *this;
}
// members functions
void btc::price_time(const btc &src){
	std::ifstream input (this->_filename.c_str());
	if (!input)
		throw std::runtime_error("Error opening <file>.txt");
	std::string date;
	double value;
	std::string line;
	while (std::getline(input, line))
	{
		if (!get_file_date(line))
			std::cerr<<"Error: bad input =>" << line << std::endl;
		else
		{
			date = line.substr(0,9);
			if (get_file_value(line) == -1)
				std::cerr<<"Error: bad input =>" << line << std::endl;
			else if (get_file_value(line) == -2)
				std::cerr<<"Error: not a positive number." << std::endl;
			else if (get_file_value(line) == -3)
				std::cerr<<"Error: too large a number." << std::endl;
		}
	}
}
void btc::init(const std::string &filename){
	std::ifstream input("data.csv");
	if (!input)
		throw std::runtime_error("Error opening the csv file");
	std::string line;
	while (std::getline(input, line)){
		this -> data_csv[get_csv_key(line)] = get_csv_value(line);
	}
	input.close();
}

// none members functions

bool valid_digit(const std::string& date, int start, int end)
{
	for (start; start < end; start++)
	{
		if (!isdigit(date.at(start)))
			return false;
	}
	return true;
}

bool check_date_format(const std::string& date)
{
	if (date.at(4) != '-' || date.at(7) != '-')
		return false;
	if (!valid_digit(date, 0, 4) || !valid_digit(date, 5, 7) || !valid_digit(date, 8, 10))
		return false;
	return true;
}

bool get_file_date(const std::string& line)
{
	std::string::size_type idx = line.rfind('|');
	if (idx == std::string::npos || idx != 11)
		return (false);
	if (!check_date_format(line.substr(0,9)))
		return (false);
	return true;
}
double ft_stod(const std::string str)
{
    double num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}
bool check_value(const std::string& value)
{
	if (value.length() < 2)
		return false;
	int i = 0;
	if (value.at(1) == '-')
		i++;
	if (!valid_digit(value, 1 + i, value.length()))
		return false;
	return true;
}
double get_file_value(const std::string& line)
{
	std::string::size_type idx = line.rfind('|');
	if (idx == std::string::npos || idx != 11)
		return (-1);
	if (!check_value(line.substr(12)))
		return (-1);
	double num = ft_stod(line.substr(13));
	if (num < 0)
		return (-2);
	if (num > 2147483647)
		return (-3);
	return (num);
}

std::string get_csv_key(const std::string& line)
{
	if (line.length() < 11 || line.at(9) != ',')
		throw (std::invalid_argument("There is an error in the CSV file"));
	if (!check_date_format(line.substr(0,8)))
		throw (std::invalid_argument("There is an error in the CSV file"));
	return line.substr(0,9);
}

double get_csv_value(const std::string& line)
{
	if (!check_value(line.substr(10)))
		throw (std::invalid_argument("There is an error in the CSV file"));
	return (ft_stod(line.substr(10)));
}