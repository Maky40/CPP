/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:51:31 by mnie              #+#    #+#             */
/*   Updated: 2024/07/09 13:09:49 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>
#include <iostream>

class ScalarConverter{

    private :
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter& operator=(const ScalarConverter &change);

    public :
    ~ScalarConverter();
    static void convert(std::string input);

};

#endif