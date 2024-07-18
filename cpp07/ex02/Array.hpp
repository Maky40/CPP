/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:54:15 by mnie              #+#    #+#             */
/*   Updated: 2024/07/17 17:34:03 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

template< typename T >
class Array
{
    private:
        T* array;
        unsigned int size_;
    public:
        Array() : size_(0)
        {
            this->array = new T[0];
        }
        Array(unsigned int n) : size_(n)
        {
            this->array = new T[size_];
        }
        Array(Array const & src) : size_(src.size_)
        {
            this->array = new T[size_];
            for (unsigned int i = 0; i < size_; i++)
                this->array[i] = src.array[i];
        }
        ~Array()
        {
            delete[] array;
        }
        Array & operator=(Array const & rhs)
        {
            if (this != &rhs)
            {
                delete[] array;
                this->size_ = rhs.size_;
                this->array = new T[size_];
                for (unsigned int i = 0; i < size_; i++)
                    this->array[i] = rhs.array[i];
            }
            return (*this);
        }
        T & operator[](unsigned int i) const
        {
            if (i >= size_)
                throw std::out_of_range("Out of bounds freroooooot");
            return this->array[i];
        }
        unsigned int size() const
        {
            return this->size_;
        }
};

#endif