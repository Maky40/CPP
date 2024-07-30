/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:21:40 by mnie              #+#    #+#             */
/*   Updated: 2024/07/30 18:07:59 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

rpn::rpn(){
    this -> tokens = "+-/*";
}
rpn::rpn(const rpn &src){*this = src;}
rpn::~rpn(){}
rpn &rpn::operator=(const rpn &src){
    if (this != &src)
    {
        this -> tokens = src.tokens;
        this -> stack = src.stack;
    }
    return (*this);
}

void rpn::execute(std::string &polish)
{
    int i;
    int print;

    i = 0;
    int len = polish.length();
    while (i < len)
    {
        this->separate_push(polish, &i);
        i++;
    }
    print = this->stack.top();
    this->stack.pop();
    std::cout << print;
    while (!this->stack.empty()){
        std::cout<< " ";
        print = this->stack.top();
        std::cout << print;
        this->stack.pop();
    }
    std::cout <<"\n";
}
void rpn::separate_push(std::string &polish, int* i){
     while (polish.at(*i) == ' ')
        (*i)++;
    std::string::size_type idx = polish.find(' ', *i);
    if (idx == std::string::npos) {
        idx = polish.length();
    }
    std::string word = polish.substr(*i, idx - *i);
    if (!check_value(word))
        throw (std::invalid_argument("This is not an inverted Polish mathematical expression"));
    *i = idx;
    this->push(word);
}

void rpn::push(const std::string &word){
    if (isdigit(word.at(0)))
    {
        double num = atof(word.c_str());
        if(num > 2147483647)
            throw (std::invalid_argument("An argument is > INT MAX"));
        if (num < -2147483648)
            throw (std::invalid_argument("An argument is < INT MIN"));
        this -> stack.push(atoi(word.c_str()));
    }
    else
        this->operations(word);
}

void rpn::operations(const std::string &word){
    int result;
    if (this -> stack.size() < 2)
        throw (std::invalid_argument("This is not an inverted Polish mathematical expression"));
    int b = this -> stack.top();
    this -> stack.pop();
    int a = this -> stack.top();
    this -> stack.pop();
    switch (word.at(0))
    {
    case '/':
        result = a / b;
        this -> stack.push(result);
        break;
    case '*':
        result = a * b;
        this -> stack.push(result);
        break;
    case '+':
        result = a + b;
        this -> stack.push(result);
        break;
    case '-':
        result = a - b;
        this -> stack.push(result);
        break;
    default:
        throw (std::invalid_argument("This is not an inverted Polish mathematical expression"));
        break;
    }
}
bool rpn::check_value(std::string& word)
{
    if (word.length() != 1)
        throw (std::invalid_argument("An argument has more than 1 digit"));
    if (!isdigit(word.at(0)))
    {
        for (int i = 0; i < 4; i++)
        {
            if(word.at(0) == this -> tokens.at(i))
                return true;
        }
        return false;
    }
    return true;
}
