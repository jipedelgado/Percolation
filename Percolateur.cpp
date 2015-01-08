#include "Percolateur.h"

Percolateur::Percolateur(int width, int height)
{
 // initialise grid
  Width = width;
  Height = height;
  this->size = width * height;

  // initialise openSites, aucun ouverts au démarrage
  openSites = new vector<int> ;
  for(int i = 0; i<size; i++)
    openSites->push_back(0);

  // initialise le tableau des sites fermés, tous au démarrage
   closedSites = new vector<int> ;
   for( int i = 0; i<size ; i++)
     closedSites->push_back(i);

  // initialise WeightedQuickUnionUF quickUnion(size)
  quickUnion  = new WeightedQuickUnionUF (size);
}

// --------------------------------------------------------------------------------------

vector<int> Percolateur::neighbours(int n){
// retourne un vecteur composé des voisins autorisés d'un site
  vector<int> v;
  if( n/Width == (n+1)/Width) v.push_back(n+1);
  if (n !=0 && n/Width == (n-1)/Width) v.push_back(n-1);
  if( n + Width < Width * Height) v.push_back(n+Width);
  if( n-Width >= 0) v.push_back(n-Width);
  return v;
}

// --------------------------------------------------------------------------------------

int Percolateur::extractRandomElementFrom(vector<int> *vi){
  /* choisit au hasard un élément d'un vecteur, le retire de ce vecteur, et le retourne.
   * attention, l'ordre des éléments du vecteur n'est pas conservé, ce qui est
   * sans importance pour cette application.
   * La complexité est d'ordre zéro, une lecture + une affectaion, un pop
  */

  // on tire au hasard un nombre dans l'intervalle [0, v.size()[
  vector<int> *v = new vector<int>;
  v = vi;
  int s = v->size();
  int randomIndex = rand()%(v->size());
  try{
    // l'élément situé à cet emplacement
    int value = v->at(randomIndex);

    // on recopie le dernier élément à cet emplacement
    v->at(randomIndex) = v->back();

    // on retire le dernier élément
    v->pop_back();

    return value;
  }
  catch(int e){
    cout<<"erreur "<<e<<" in extractRandomElementFrom"<<endl;
  }
  return 2;
}

// --------------------------------------------------------------------------------------

int Percolateur::newSite(){
  if (!closedSites->empty())
    return extractRandomElementFrom(this->closedSites);
}

// --------------------------------------------------------------------------------------

void Percolateur::open(int s){
  openSites->at(s) = 1;
  for(auto n: neighbours(s)){
      if( openSites->at(n) != 0){
          quickUnion->Union(s, n);
        }
    }
}

// --------------------------------------------------------------------------------------

bool Percolateur::percolate(){
// le systéme percole ?
  for(int i = size-1 ; i>size-Width; i--)
    for(int j=0 ; j<Width; j++)
      if(quickUnion->connected(i,j))
        return true;
  return false;
}


