#include <iostream>
#include <list>

// Fonction pour trier une std::list
void sortList(std::list<int>& lst) {
    // Implémentation simple du tri à bulles (bubble sort)
    for (auto it1 = lst.begin(); it1 != lst.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != lst.end(); ++it2) {
            if (*it2 < *it1) {
                std::iter_swap(it1, it2);
            }
        }
    }
}

// Fonction pour insérer les éléments d'une liste source dans une liste destination de manière triée
void insertSorted(std::list<int>& dest, std::list<int>& src) {
    auto itDest = dest.begin();
    auto itSrc = src.begin();

    while (itSrc != src.end()) {
        // Insérer les éléments de src dans dest de manière triée
        while (itDest != dest.end() && *itDest <= *itSrc) {
            ++itDest;
        }
        // Insère itSrc à la bonne position dans dest
        itDest = dest.insert(itDest, *itSrc);
        ++itSrc;
    }
    src.clear();  // Efface les éléments de src après insertion
}

int main() {
    // Création d'un tableau de 3 listes
    std::list<int> array[3];

    // Ajouter des valeurs à chaque liste
    array[0] = {3, 1};  // Liste 0: 3, 1
    array[1] = {8, 2};  // Liste 1: 8, 2
    array[2] = {7, 5};  // Liste 2: 7, 5

    // Étape 2 : Trier chaque liste avec notre propre fonction
    for (int i = 0; i < 3; ++i) {
        sortList(array[i]);
    }

    // Affichage des listes triées
    std::cout << "Listes après le tri:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Liste " << i << ": ";
        for (int val : array[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Étape 3 : Insérer les éléments de la liste 1 dans la liste 0 de manière triée
    insertSorted(array[0], array[1]);

    // Insérer les éléments de la liste 2 dans la liste 1 (qui est maintenant vide)
    insertSorted(array[1], array[2]);

    // Affichage des listes après les insertions
    std::cout << "\nListes après insertion triée:" << std::endl;
    std::cout << "Liste 0: ";
    for (int val : array[0]) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Liste 1: ";
    for (int val : array[1]) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Liste 2: ";
    for (int val : array[2]) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}