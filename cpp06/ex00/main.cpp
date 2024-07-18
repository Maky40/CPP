/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:55:28 by mnie              #+#    #+#             */
/*   Updated: 2024/07/16 10:11:01 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

using std::cerr;

int	main(int argc, char **argv)
{
    if (argc != 2 || !argv[1][0])
    {
        cerr << "Usage: ./convert <input>" << "\n";
        return EXIT_FAILURE;
    }
    ScalarConverter::convert(argv[1]);
    return EXIT_SUCCESS;
}