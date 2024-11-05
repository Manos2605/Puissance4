#include "../header/jeux.h"
#include <iostream>

void drawgrid(int grille[7][6]) {
    for (int ligne = 0; ligne < 6; ligne++) {
        std::cout << "|";
        for (int col = 0; col < 7; col++) {
            if (grille[col][ligne] == 1) {
                std::cout << "X ";
            } else if (grille[col][ligne] == 2) {
                std::cout << "O ";
            } else {
                std::cout << "* ";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool placeToken(int grille[7][6], int col, int player) {
    for (int ligne = 5; ligne >= 0; ligne--) { 
        if (grille[col][ligne] == 0) {
            grille[col][ligne] = player;
            return true;
        }
    }
    return false;
}

bool Win(int grille[7][6], int player) {
    for (int col = 0; col < 7; col++) {
        for (int ligne = 0; ligne < 6; ligne++) {
            // Vérification horizontale
            if (col <= 3 &&
                grille[col][ligne] == player &&
                grille[col + 1][ligne] == player &&
                grille[col + 2][ligne] == player &&
                grille[col + 3][ligne] == player) {
                return true;
            }
            // Vérification verticale
            if (ligne <= 2 && 
                grille[col][ligne] == player && 
                grille[col][ligne + 1] == player &&
                grille[col][ligne + 2] == player && 
                grille[col][ligne + 3] == player) {
                return true;
            }
            // Vérification diagonale
            if (col <= 3 && 
                ligne <= 2 && 
                grille[col][ligne] == player &&
                grille[col + 1][ligne + 1] == player &&
                grille[col + 2][ligne + 2] == player &&
                grille[col + 3][ligne + 3] == player) {
                return true;
            }
            // Vérification diagonale inverse
            if (col <= 3 && 
                ligne >= 3 && 
                grille[col][ligne] == player &&
                grille[col + 1][ligne - 1] == player && 
                grille[col + 2][ligne - 2] == player &&
                grille[col + 3][ligne - 3] == player) {
                return true;
            }
        }
    }
    return false;
}
