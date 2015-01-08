#ifndef PERCOLATEUR_H
#define PERCOLATEUR_H
#include <vector>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

#include "Site.h"
#include "WeightedQuickUnionUF.h"

using namespace std;

class Percolateur
{
  WeightedQuickUnionUF *quickUnion;

  // choisit au hasard un élément d'un vecteur, le retire de ce vecteur, et le retourne.
  int extractRandomElementFrom(vector<int>*);

public:
  int Width;
  int Height;
  int size;

  // les indices des sites ouverts
  vector<int> *openSites;

  // les indices des sites fermés
  vector<int> *closedSites;

  // retourne un vecteur composé des voisins autorisés d'un site
  vector<int> neighbours(int);

  // constructeur
  Percolateur(int width = 0, int height = 0);

  // l'indice d'un site tiré par extractRandomElementFrom
  int newSite();

  // on ouvre un site
  void open(int);

  // le systéme percole ?
  bool percolate();

};

#endif // PERCOLATEUR_H
