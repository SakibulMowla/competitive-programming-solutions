// CERC 2012
// Problem F: Farm and factory
// Output checker
// Author: Jakub Pachocki

#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

const long double eps_rel = 1e-8+1e-9; // relative error
const long double eps_abs = 1e-8+1e-9; // absolute error

int main(int argc, char **argv)
{
  assert(argc==4);
  FILE* fin = fopen(argv[1],"r");
  FILE* fsol = fopen(argv[2],"r");
  FILE* fout = fopen(argv[3],"r");
  assert(fin != 0);
  assert(fsol != 0);
  assert(fout != 0);
  int TT;
  assert(fscanf(fin,"%d",&TT)==1);
  for(int tt=1; tt<=TT; tt++)
  {
    long double x,y;
    assert(fscanf(fsol,"%Lf",&x)==1);
    assert(fscanf(fout,"%Lf",&y)==1);
    if (abs(x-y)>eps_abs && (abs(x)<eps_abs || abs(x-y)/x>eps_rel))
    {
      printf("Test %d: expected %Lf, got %Lf.\n",tt,x,y);
      return 1;
    }
  }
  fscanf(fout," ");
  assert(feof(fout));
  return 0;
}
