#ifndef JOUER_H
#define JOUER_H

void drawgrid(int grille[7][6]);
bool placeToken(int grille[7][6], int col, int player);
bool Win(int grille[7][6], int player);

#endif