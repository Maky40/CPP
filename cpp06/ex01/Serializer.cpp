/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:19:48 by mnie              #+#    #+#             */
/*   Updated: 2024/07/16 13:11:08 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {};

Serializer::Serializer(const Serializer &copy) { *this = copy; }

Serializer&	Serializer::operator=(const Serializer &change) { (void)change; return *this; }

Serializer::~Serializer() {}
// public functions
Data* Serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data*>(raw));
}
uintptr_t Serializer::serialize(Data* ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}

// reinterpret_cast is used to convert any pointer type to any othe pointer type (if they are not related)