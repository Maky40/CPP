/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:40:35 by mnie              #+#    #+#             */
/*   Updated: 2024/06/10 11:17:41 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook_include.hpp"

Phonebook::Phonebook()
{
    size = 0;
}

Phonebook::~Phonebook()
{
}

void    Phonebook::replace_values(int pos)
{
    arrContact[pos].set_values(arrContact[pos+1].get_fn(), arrContact[pos+1].get_n(), \
                                arrContact[pos+1].get_nn(), arrContact[pos+1].get_ph(),\
                                 arrContact[pos+1].get_ds());
}

void    Phonebook::addContact(std::string fn, std::string n, std::string nn, \
        std::string ph, std::string ds)
{
    if (size < 8)
    {
        arrContact[size].set_values(fn, n, nn, ph, ds);
        size++;
    }
    else
    {
        size = 0;
        while (size != 7)
        {
            replace_values(size);
            size++;
        }
        arrContact[size].set_values(fn, n, nn, ph, ds);
        size = 8;
    }
}

void    Phonebook::print_contacts()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First name" << "|"
              << std::setw(10) << "Last name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    for (int i = 0; i < size; i++)
    {
        arrContact[i].print_values(i);
    }
}

void    Phonebook::choose_contact()
{
    std::string index;

    std::cout<<"Select a Contact : ";
    std::getline(std::cin, index);
    for (size_t i = 0; i < index.size(); i++)
    {
        if (!isdigit(index[i]))
        {
            index = "100";
            break ;
        }
    }
    while (atoi(index.c_str()) >= size)
    {
        std::cout<<"Select a valid index please : ";
        std::getline(std::cin, index);
        for (size_t i = 0; i < index.size(); i++)
        {
            if (!isdigit(index[i]))
            {
                index = "100";
                break ;
            }
        }
    }
    arrContact[atoi(index.c_str())].print_informations();
}