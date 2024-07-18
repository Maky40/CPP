/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:54:36 by mnie              #+#    #+#             */
/*   Updated: 2024/07/16 17:25:26 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

#define BLUE "\033[94m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#include <string>
#include <iostream>

class Base{
    public :
    // destructor
    virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base    *generate(void);
void    identify(Base* p);
void    identify(Base& p);
#endif