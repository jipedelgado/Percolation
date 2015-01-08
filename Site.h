#ifndef SITE_H
#define SITE_H

#include <iostream>

using namespace std;

class Site
{
public:
  int row, column,Id, root;
  Site();
  Site(int r, int c, int N);

  friend ostream& operator<<(ostream& out, Site* s){
    out<<"row = "<<s->row<<"   column = "<<s->column<<"    N = "
      <<s->Id<<"   root = "<<s->root<<endl;
    return out;
  }
};

#endif // SITE_H
