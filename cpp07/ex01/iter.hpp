/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:06:54 by mnie              #+#    #+#             */
/*   Updated: 2024/07/17 14:33:16 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>
#include <string>

template<typename T, typename U>
void iter(T *array, int len, void (*f)(U))
{
    for(int i = 0; i < len; i++)
		f(array[i]);
}

#endif