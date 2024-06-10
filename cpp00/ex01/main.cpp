/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:40:38 by mnie              #+#    #+#             */
/*   Updated: 2024/06/10 11:13:35 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook_include.hpp"

void search_contact(Phonebook &phonebook)
{
    phonebook.print_contacts();
    phonebook.choose_contact();
}

void add_contact(Phonebook &phonebook)
{
    std::string fn, n, nn, ph, ds;

    std::cout << "Enter first name: ";
    std::getline(std::cin, fn);
    std::cout << "Enter last name: ";
    std::getline(std::cin, n);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nn);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, ph);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, ds);

    phonebook.addContact(fn, n, nn, ph, ds);
}

int main()
{
    Phonebook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "Enter command (ADD, SEARCH or EXIT) : ";
        std::getline(std::cin, command);
        if (command == "ADD")
            add_contact(phonebook);
        else if (command =="SEARCH")
            search_contact(phonebook);
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Invalid command." << std::endl;
    }
    return (0);
}