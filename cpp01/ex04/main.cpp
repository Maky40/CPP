/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:37:29 by mnie              #+#    #+#             */
/*   Updated: 2024/05/30 18:38:33 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
	// Ouvrir le fichier d'entrée
	std::ifstream input(filename.c_str());
	if (!input) {
		std::cerr << "Erreur lors de l'ouverture du fichier d'entrée." << std::endl;
		return;
	}

	// Ouvrir le fichier de sortie
	std::ofstream output((filename + ".replace").c_str());
	if (!output) {
		std::cerr << "Erreur lors de l'ouverture du fichier de sortie." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(input, line)) {
		// Recherche et remplace les occurrences de s1 par s2 dans la ligne
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.replace(pos, s1.length(), s2);
			pos += s2.length(); // Pour éviter une boucle infinie si s2 contient s1
		}
		// Écrire la ligne modifiée dans le fichier de sortie
		output << line << std::endl;
	}

	// Fermer les fichiers
	input.close();
	output.close();
}

int main(int argc, char* argv[]) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	replaceInFile(filename, s1, s2);

	std::cout << "Remplacement terminé. Consultez le fichier " << filename << ".replace." << std::endl;

	return 0;
}
