/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:38:22 by mnie              #+#    #+#             */
/*   Updated: 2024/05/27 13:46:28 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else 
    {
        for (int i = 1; argv[i]; i++)
        {
            for (int j = 0; argv[i][j]; j++)
                std::cout << (char) toupper(argv[i][j]);
            if (i < argc - 1)
                std::cout << ' ';
        }
    }
    std::cout << std::endl;
    return (0);
}