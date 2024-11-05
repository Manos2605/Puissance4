#include "../header/joueur.h"
#include <iostream>
#include <string>

int ColonneJoueur(int player) {
    std::string choix;
    int col;

    while (true) {
        std::cout << "Joueur " << player << " colonne(1-7) : ";
        std::cin >> choix;

        if (choix == "exit") {
            return -1; // Indicateur pour quitter
        }

        try {
            col = std::stoi(choix) - 1;
            if (col >= 0 && col < 7) {
                return col;
            } else {
                throw std::out_of_range("Colonne invalide");
            }
        } catch (...) {
            std::cout << "Entrée invalide. Veuillez entrer un nombre entre 1 et 7.\n";
        }
    }
}
