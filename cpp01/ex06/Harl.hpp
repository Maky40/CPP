/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:30:52 by mnie              #+#    #+#             */
/*   Updated: 2024/05/30 20:46:37 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <string>
#include <iostream>
#include <cstdlib>

class Harl
{
	private:
			void debug(void);
			void info(void);
			void warning(void);
			void error(void);
	public:
			Harl();
			~Harl();
			void complain(std::string level);
};

#endif