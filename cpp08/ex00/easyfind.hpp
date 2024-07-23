/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:54:15 by mnie              #+#    #+#             */
/*   Updated: 2024/07/22 17:08:40 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>

class NotFind : public std::exception
{
	public:

	virtual const char* what() const throw()
	{
		return ("Can't find integer !");
	}
};

template< typename T >
bool	easyfind(const T container, const int toFind)
{
	if (std::find(container.begin(), container.end(), toFind) == container.end())	
		return (false);
	return (true);
}
#endif