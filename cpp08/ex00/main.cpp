/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:21:06 by mnie              #+#    #+#             */
/*   Updated: 2024/07/22 17:07:46 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
	try
	{
		std::cout << "vector : " << std::endl;
		std::vector<int>	vect;
		vect.push_back(-43);
		vect.push_back(-21);
		vect.push_back(-4);
		vect.push_back(78);
		std::cout << easyfind(vect, 78) << std::endl;
		std::cout << easyfind(vect, 0) << std::endl;
	}
	catch(const NotFind& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		std::cout << "list : " << std::endl;
		std::list<int>	myList;
		myList.push_back(-21);
		myList.push_back(-43);
		myList.push_back(-4);
		myList.push_back(78);
		std::cout << easyfind(myList, 78) << std::endl;
		std::cout << easyfind(myList, 0) << std::endl;
	}
	catch(const NotFind& e)
	{
		std::cerr << e.what() << '\n';
	}
		
	return (0);
}