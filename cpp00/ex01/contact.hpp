/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:40:40 by mnie              #+#    #+#             */
/*   Updated: 2024/06/10 11:13:38 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "phonebook_include.hpp"

class Contact
{
private:

        std::string name;
        std::string first_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

public:
        Contact();
        ~Contact();
        void            set_values(std::string fn, std::string n, std::string nn, \
                        std::string ph, std::string ds);
        void            print_values(int i);
        void            print_informations();
        std::string     get_fn();
        std::string     get_n();
        std::string     get_nn();
        std::string     get_ph();
        std::string     get_ds();
};

#endif