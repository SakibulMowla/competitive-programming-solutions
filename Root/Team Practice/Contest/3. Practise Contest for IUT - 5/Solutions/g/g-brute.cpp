// CERC 2012
// Problem G: Jewel heist
// Slow solution (checking every cap point), O(n^2)
// Author: Lech Duraj

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 200*1000;

struct jewel
{
  int x, y, c;
};

jewel A[maxn];
int L[maxn+1];

bool cmpx(jewel a, jewel b)
{
  return a.x<b.x;
}

int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
      scanf("%d%d%d",&A[i].x,&A[i].y,&A[i].c);
    sort(A,A+n,cmpx);
    int m = 0;
    for(int i=0; i<n; i++)
    {
      int cl = 0;
      int last = 0;
      for(int j=0; j<i; j++)
      {
        if (A[j].y>=A[i].y)
          continue;
        if (A[j].c==A[i].c)
        {
          cl = 0;
          last = A[j].x;
        }    
        if (A[j].c!=A[i].c && A[j].x>last)
          cl++;
      }
      int cr = 0;
      last = A[n-1].x+1;
      for(int j=n-1; j>i; j--)
      {
        if (A[j].y>=A[i].y)
          continue;
        if (A[j].c==A[i].c)
        {
          cr = 0;
          last = A[j].x;
        }
        if (A[j].c!=A[i].c && A[j].x<last)
          cr++;
      }
      m = max(m,cl+cr);
    }
    for(int j=1; j<=k; j++)
      L[j] = -1;
    int q = 0;
    while(q<n)
    {
      int i = q;
      while(i<n && A[i].x==A[q].x)
      {
        m = max(m,q-L[A[i].c]-1);
        i++;
      }
      int j = i;
      i = q;
      while(i<n && A[i].x==A[q].x)
      {
        L[A[i].c] = j-1;
        i++;
      }
      q = j;
    }
    for(int j=1; j<=k; j++)
      m = max(m,n-1-L[j]);
    printf("%d\n",m);
  }
}
