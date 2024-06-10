/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:40:43 by mnie              #+#    #+#             */
/*   Updated: 2024/06/10 11:23:33 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook_include.hpp"

Contact::Contact()
{
}
Contact::~Contact()
{
}

void Contact::set_values(std::string n, std::string fn, std::string nn, std::string ph, std::string ds)
{
    name = n;
    first_name = fn;
    nickname = nn;
    phone_number = ph;
    darkest_secret = ds;
}
void print_column(std::string str)
{
    size_t size;

    size = str.size();
    if (size < 11)
    {
       std::cout << std::setw(10) << str;
    }
    else
    {
		std::cout << std::setw(10) << str.substr(0, 9) + ".";
    }
    std::cout<<"|";
}
void Contact::print_values(int i)
{
    std::cout<<"         " << i << "|";
    print_column(this->first_name);
    print_column(this->name);
    print_column(this->nickname);
    std::cout<<"\n";
}
void Contact::print_informations()
{
    std::cout<<"Fist name : "<<this -> first_name<<std::endl;
    std::cout<<"Name : "<<this ->name<<std::endl;
    std::cout<<"Nickname : "<<this -> nickname<<std::endl;
    std::cout<<"Phone number : "<<this -> phone_number<<std::endl;
    std::cout<<"Darkest secret : "<<this -> darkest_secret<<std::endl;
}
std::string Contact::get_fn()
{
    return (first_name);
}

std::string Contact::get_n()
{
    return (name);
}

std::string Contact::get_nn()
{
    return (nickname);
}

std::string Contact::get_ph()
{
    return (phone_number);
}

std::string Contact::get_ds()
{
    return (darkest_secret);
}