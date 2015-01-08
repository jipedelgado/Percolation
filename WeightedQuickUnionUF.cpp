#include "WeightedQuickUnionUF.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(int N)
{
  Count = N;

  id = new vector<int> (N, 0);
  for(int i = 0; i<N; i++)
    id->at(i) = i;

  sz = new vector<int> (N, 1);

}

bool WeightedQuickUnionUF::connected(int p, int q)
{
  return find(p) == find(q);
}

int WeightedQuickUnionUF::find(int p)
{
  while( p != id->at(p))
    p = id->at(p);
  return p;
}

void WeightedQuickUnionUF::Union(int p, int q)
{
  int i = find(p);
  int j = find(q);
  if( i==j ) return;

  if(sz->at(i) < sz->at(j)){
      id->at(i) = j;
      sz->at(j) += sz->at(i);
    }
  else{
      id->at(j) = i;
      sz->at(i) += sz->at(j);
    }
  Count--;
}


