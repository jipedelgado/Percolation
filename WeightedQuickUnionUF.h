#ifndef WEIGHTEDQUICKUNIONUF_H
#define WEIGHTEDQUICKUNIONUF_H

#include <vector>

using namespace std;

class WeightedQuickUnionUF
{
private:
  vector<int> *id;
  vector<int> *sz;
  int Count;

public:
  WeightedQuickUnionUF(int N);
  int count(){ return Count;}
  bool connected(int, int);
  int find(int);
  void Union(int, int);

};

#endif // WEIGHTEDQUICKUNIONUF_H
