#include "Site.h"

Site::Site(){
}

Site::Site(int r, int c, int N)
{
  row = r;
  column = c;
  Id = r*N+c+1;
  root = 0;
}
