/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:21:06 by mnie              #+#    #+#             */
/*   Updated: 2024/08/09 14:41:38 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main() {
    // Test du constructeur par défaut
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test du constructeur par défaut : " << RESET << std::endl;
    Array<int> arr1;
    std::cout << GREEN << "Taille de arr1 (doit être 0) : " << arr1.size() << RESET << std::endl;

    // Test du constructeur avec une taille
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test du constructeur avec taille : " << RESET << std::endl;
    Array<int> arr2(5);
    std::cout << GREEN << "Taille de arr2 (doit être 5) : " << arr2.size() << RESET << std::endl;

    // Test de l'initialisation par défaut des éléments
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test de l'initialisation par défaut des éléments : " << RESET << std::endl;
    std::cout << GREEN << "Éléments de arr2 (doivent être 0) : ";
    for (unsigned int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << RESET << std::endl;

    // Test de l'accès aux éléments avec l'opérateur []
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test de l'accès aux éléments avec l'opérateur [] : " << RESET << "\n" << GREEN << "Element 0 = 42, element 1 = 21" << std::endl;
    arr2[0] = 42;
    arr2[1] = 21;
    std::cout << GREEN << "arr2[0] = " << arr2[0] << ", arr2[1] = " << arr2[1] << RESET << std::endl;

    // Test de l'opérateur de copie
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test de l'opérateur de copie : " << RESET << std::endl;
    Array<int> arr3(arr2);
    std::cout << GREEN << "Taille de arr3 après copie (doit être 5) : " << arr3.size() << RESET << std::endl;
    std::cout << GREEN << "Éléments de arr3 après copie : ";
    for (unsigned int i = 0; i < arr3.size(); ++i) {
        std::cout << arr3[i] << " ";
    }
    std::cout << RESET << std::endl;

    // Test de la modification après la copie (vérification de l'indépendance des copies)
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test de la modification après la copie : " << RESET << std::endl;
    arr2[2] = 84;
    std::cout << GREEN << "arr2[2] après modification = " << arr2[2] << RESET << std::endl;
    std::cout << GREEN << "arr3[2] après modification de arr2 (doit être différent) = " << arr3[2] << RESET << std::endl;

    // Test de l'opérateur d'affectation
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test de l'opérateur d'affectation : " << RESET << std::endl;
    Array<int> arr4;
    arr4 = arr2;
    std::cout << GREEN << "Taille de arr4 après affectation (doit être 5) : " << arr4.size() << RESET << std::endl;
    std::cout << GREEN << "Éléments de arr4 après affectation : ";
    for (unsigned int i = 0; i < arr4.size(); ++i) {
        std::cout << arr4[i] << " ";
    }
    std::cout << RESET << std::endl;

    // Test avec des types non entiers (float)
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test avec des floats : " << RESET << std::endl;
    Array<float> arrFloat(3);
    arrFloat[0] = 1.23f;
    arrFloat[1] = 4.56f;
    arrFloat[2] = 7.89f;
    std::cout << GREEN << "Éléments de arrFloat : ";
    for (unsigned int i = 0; i < arrFloat.size(); ++i) {
        std::cout << arrFloat[i] << " ";
    }
    std::cout << RESET << std::endl;

    // Test avec des types complexes (std::string)
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test avec des std::string : " << RESET << std::endl;
    Array<std::string> arrString(2);
    arrString[0] = "Hello";
    arrString[1] = "World";
    std::cout << GREEN << "Éléments de arrString : ";
    for (unsigned int i = 0; i < arrString.size(); ++i) {
        std::cout << arrString[i] << " ";
    }
    std::cout << RESET << std::endl;

    // Test des exceptions pour accès hors limites
    std::cout << CYAN << "------------------------------" << RESET << std::endl;
    std::cout << BLUE << "Test des exceptions pour accès hors limites : " << RESET << std::endl;
    try {
        std::cout << RED << "Tentative d'accès hors limites arr2[10] : " << arr2[10] << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Exception capturée : " << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << "------------------------------" << RESET << std::endl;

    return 0;
}
