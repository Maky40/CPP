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
void btc::price_time(){
    std::ifstream input (this->_filename.c_str());
    if (!input)
        throw std::runtime_error("Error opening <file>.txt");
    std::string date;
    double value;
    std::string line;
	std::getline(input, line);
    while (std::getline(input, line))
    {
        if (!get_file_date(line))
            std::cerr<<"Error: bad input => " << line << std::endl;
        else
        {
            date = line.substr(0,10);
            value = get_file_value(line);
            if (value == -1)
                std::cerr<<"Error: bad input => " << line << std::endl;
            else if (value == -2)
                std::cerr<<"Error: not a positive number." << std::endl;
            else if (value == -3)
                std::cerr<<"Error: too large a number." << std::endl;
            else 
                this->bitcoin_value(date, value);
        }
    }
}
void btc::init(){
    std::ifstream input("data.csv");
    if (!input)
        throw std::runtime_error("Error opening the csv file");
    std::string line;
    std::getline(input, line);
    if (line != "date,exchange_rate")
        throw (std::invalid_argument("Error in CSV file, first line must be 'date,exchange_rate'"));
    while (std::getline(input, line))
        this -> data_csv[get_csv_key(line)] = get_csv_value(line);
    input.close();
}

void btc::bitcoin_value(const std::string &date, const double &value)
{
    std::map<std::string, double>::iterator it = this -> data_csv.lower_bound(date);
    if (it == this -> data_csv.begin()) /*No match found */
        std::cout << "Error: the date is earlier than the first date in the <file>.txt" << std::endl;
    else
	{
		if (value * it -> second > 2147483647)
			std::cerr<<"Error: too large a number." << std::endl;
		else
			std::cout << date << " => " << value << " = " << value * it -> second << std::endl;
	}
        
}

// none members functions

bool valid_digit(const std::string& date, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (!isdigit(date.at(i)))
            return false;
    }
    return true;
}

bool check_date_format(const std::string& date)
{
    if (date.at(4) != '-' || date.at(7) != '-')
        return false;
    if (!valid_digit(date, 0, 4) || !valid_digit(date, 5, 7) || !valid_digit(date, 8, 10)){
        return false;}
	if (atoi(date.substr(5,6).c_str()) > 12 || atoi(date.substr(8,9).c_str()) > 31){
		return false;}
    return true;
}

bool get_file_date(const std::string& line)
{
    std::string::size_type idx = line.rfind('|');
    if (idx == std::string::npos || idx != 11)
        return (false);
    if (!check_date_format(line.substr(0,10))){
        return (false);}
	if (line.at(10) != ' '){
		return (false);}
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
	int decimal_point = 0;
	int i = 0;
    if (value.length() < 1)
        return false;
    if (value.at(0) == '+' || value.at(0) =='-')
        i++;
    for (size_t start = i; start < value.length(); start++)
	{
		if (!isdigit(value.at(start)))
		{
			if (value.at(start) != '.')
				return false;
			decimal_point += 1;
			if (decimal_point > 1)
				return false;
		}
	}
    return true;
}
double get_file_value(const std::string& line)
{
    std::string::size_type idx = line.rfind('|');
    if (idx == std::string::npos || idx != 11){
        return (-1);}
	if (line.at(12) != ' '){
		return (-1);}
    if (!check_value(line.substr(13)))
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
    if (line.length() < 11 || line.at(10) != ',')
        throw (std::invalid_argument("There is an error in the CSV file (data invalid)"));
    if (!check_date_format(line.substr(0,10))){
        throw (std::invalid_argument("There is an error in the CSV file (date invalid)"));}
    return line.substr(0,10);  // 10 chars for date in the format YYYY-MM-DD
}

double get_csv_value(const std::string& line)
{
    if (!check_value(line.substr(11))){
        throw (std::invalid_argument("There is an error in the CSV file (value invalid)"));}
    return (ft_stod(line.substr(11)));
}
