/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:40:32 by mnie              #+#    #+#             */
/*   Updated: 2024/07/17 14:11:38 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

#include <string>
#include <iostream>

template<typename T>
T const &max(const T &x, const T &y){
    return (x >= y ? x : y);
}

template<typename T>
T const &min(const T &x, const T &y){
    return (x <= y ? x : y);
}

template<typename T>
void swap(T &x, T &y){
    T swap;

    swap = x;
    x = y;
    y = swap;
}

#endif