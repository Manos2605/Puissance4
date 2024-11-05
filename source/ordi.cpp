#include "../header/ordi.h"
#include "../header/jeux.h"
#include <iostream>
#include <ctime>
#include <string>

int ColonneOrdinateur(int grille[7][6]) {
    srand(time(0));
    int col;
    do {
        col = rand() % 7;
    } while (grille[col][0] != 0);  // Recommence si la colonne est pleine
    return col;
}


