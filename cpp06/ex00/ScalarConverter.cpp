/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:51:17 by mnie              #+#    #+#             */
/*   Updated: 2024/07/16 08:29:05 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

static bool isPseudoInput(const std::string input) 
{
    return (input == "-inff" || input == "+inff" || input == "nanf"
          || input == "-inf" || input == "+inf"  || input == "nan");
}
static void inputChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
static void inputInt(int nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl; 
    else
        std::cout << "char: Non displayable" << std::endl; 
    std::cout << "int: " << nbr << std::endl;
    std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}
static void inputFloat(float nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    std::cout << "float: " << nbr << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
}

static void inputDouble(double nbr)
{
    if (isprint(nbr))
        std::cout << "char: '" << static_cast<char>(nbr)  << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(nbr) << std::endl;
    std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
    std::cout << "double: " << nbr << ".0" << std::endl;
}
static void pseudoinput(int num, const std::string input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl; 
    if (num == 2)
    {
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
    }
    else if (num == 3)
    {
        std::cout << "float: " << input + "f" << std::endl;
        std::cout << "double: " << input << std::endl;
    }
}
static bool isChar(const std::string input)
{
    if (input.length() != 1)
        return false;
    if (isdigit(input.at(0)))
        return false;
    return true;
}
static bool isInt(const std::string input)
{
    size_t i = 0;

    if (input.at(0) == '-' || input.at(0) == '+')
        i++;
    for (; i < input.length(); i++)
    {
        if (!isdigit(input.at(i)))
            return false;
    }
    return true;
}

static bool isFloat(const std::string input)
{
    bool    point = false;
    size_t  i = 0;

    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;
    if (input.at(input.length() - 1) != 'f')
        return false;
    if (input.at(0) == '-' || input.at(0) == '+')
        i++;
    for (; i < input.length(); i++)
    {
        if(!isdigit(input.at(i)) && input.at(i) != '.')
            return false;
    }
    for (i = 0; i < input.length(); i++)
    {
        if (input.at(i) == '.')
        {
            if (point == true)
                return false;
            point = true;
        }
    }
    return true;
}

static bool isDouble(const std::string input)
{
    bool    found_point;

    found_point = false;
    if (input == "-inf" || input == "+inf" || input == "nan")
        return true;
    for (size_t i = 0; i < input.length(); i += 1)
    {
        if (input.at(i) == '.' && found_point)
            return false;
        else if (input.at(i) == '.')
        {
            found_point = true;
            continue ;
        }
        if (!isdigit(input.at(i)))
            return false;
    }
    return true;
}

static int getType(const std::string input)
{
    if (isChar(input))
        return 0;
    if (isInt(input))
        return 1;
    if (isFloat(input))
       return 2;
    if (isDouble(input))
       return 3;
    return 4;
}

static int ft_stoi(const std::string str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static float ft_stof(const std::string str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static double ft_stod(const std::string str)
{
    double num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

void ScalarConverter::convert(const std::string input)
{
    switch (getType(input))
    {
        case 0:
            inputChar(input.at(0));
            break;

        case 1:
            inputInt(ft_stoi(input));
            break;

        case 2:
            if (isPseudoInput(input))
                pseudoinput(2, input);
            else
                inputFloat(ft_stof(input));
            break;

        case 3:
            if (isPseudoInput(input))
                pseudoinput(3, input);
            else
                inputDouble(ft_stod(input));
            break;

        default:
            std::cout << "You choose a wrong type !" << std::endl;
            break;
    }
}