/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:12:05 by mnie              #+#    #+#             */
/*   Updated: 2024/07/30 17:36:02 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <string>
#include <iostream>
#include <stack>
#include "algorithm"
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <cctype>
#include <limits>
#include <sstream>

class rpn{
    private :
    std::stack<int> stack;
    std::string tokens;

    public :
    rpn();
    rpn(const rpn &src);
    ~rpn();
    rpn &operator=(const rpn &src);
    void execute(std::string &polish);
    void separate_push(std::string &polish, int* i);
    bool check_value(std::string& word);
    void push(const std::string &word);
    void operations(const std::string &word);
};


#endif