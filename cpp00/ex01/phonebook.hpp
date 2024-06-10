/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:40:33 by mnie              #+#    #+#             */
/*   Updated: 2024/06/10 11:13:35 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class Phonebook
{
    private:
            Contact arrContact[8];
            int     size;

    public:
            Phonebook();
            ~Phonebook();
            void    addContact(std::string fn, std::string n, std::string nn, \
        std::string ph, std::string ds);
            void    replace_values(int pos);
            void    print_contacts();
            void    choose_contact();
};

#endif