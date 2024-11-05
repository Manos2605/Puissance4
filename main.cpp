#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "header/joueur.h"
#include "header/ordi.h"
#include "header/jeux.h"

int main() {
    // Choix du mode de jeu
    int mode;
    std::cout << "Bienvenue dans Puissance 4 !\n";
    std::cout << "Choisissez un mode de jeu :\n";
    std::cout << "1. Joueur contre Joueur\n";
    std::cout << "2. Joueur contre Ordinateur\n";
    std::cin >> mode;

    bool contreOrdinateur = (mode == 2);
    int grille[7][6] = {}; // Initialisation de la grille
    int player = 1; // Le joueur 1 commence
    int scores[2] = {0, 0}; // scores

    while (true) {
        system("CLS"); // Efface l'écran
        drawgrid(grille); // Affiche la grille

        int col;
        if (contreOrdinateur && player == 2) {
            col = ColonneOrdinateur(grille);  // Ordinateur joue
            std::cout << "Ordinateur choisit la colonne " << col + 1 << "\n";
        } else {
            col = ColonneJoueur(player);  // Joueur humain joue
        }

        if (!placeToken(grille, col, player)) {
            std::cout << "Colonne pleine ! Choisissez une autre colonne.\n";
            continue;
        }

        if (Win(grille, player)) {
            system("CLS");
            drawgrid(grille);
            std::cout << "Bravo! Joueur " << player << " gagne.\n";
            scores[player - 1]++;

            char rejouer;
            std::cout << "Voulez-vous rejouer? (O/N)\n";
            std::cin >> rejouer;

            while (rejouer != 'O' && rejouer != 'o' && rejouer != 'N' && rejouer != 'n') {
                std::cout << "Entrée invalide. Veuillez entrer 'o' ou 'n'.\n";
                std::cin >> rejouer;
            }


            if (rejouer == 'N'|| rejouer == 'n') {
                break;
            }else {
                // Réinitialisation de la grille
                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 6; j++) {
                        grille[i][j] = 0;
                    }
                }
                player = 1;
                continue;
            }
            
        } else {
            // Change de joueur
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        }
    }

    // Affichage des scores
    std::cout << "Scores :\n";
    std::cout << "Joueur 1 : " << scores[0] << "\n";
    std::cout << "Joueur 2 : " << scores[1] << "\n";

    system("pause");

    return 0;
}
