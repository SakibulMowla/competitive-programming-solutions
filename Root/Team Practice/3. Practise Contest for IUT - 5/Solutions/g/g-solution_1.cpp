// CERC 2012
// Problem G: Jewel heist
// Model solution, O(n log n)
// Author: Lech Duraj

#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

const int maxn = 300*1000;

using namespace std;


typedef set<int>::iterator sit;
struct jewel
{
  int x, y, c;
};

int M;
int T[8*maxn+10];
jewel A[maxn+2];


void add(int x)
{
  int y = M+x;
  while(y>0)
  {
    T[y]++;
    y/=2;
  }
}

int query(int x)
{
  int res = 0;
  int y = M+x;
  while(y>0)
  {
    if (y%2==0)
      res += T[y--];
    y /= 2;
  }
  return res;
}


int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> vals;
    map<int,int> valmap;
    for(int i=0; i<n; i++)
    {
      scanf("%d%d%d",&A[i].x,&A[i].y,&A[i].c);
      vals.push_back(A[i].x);
      vals.push_back(A[i].y);
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=0; i<vals.size(); i++)
      valmap[vals[i]] = i+1;
    vector<int> layer[2*n+4];
    for(int i=0; i<n; i++)
    {
      A[i].x = valmap[A[i].x];
      A[i].y = valmap[A[i].y];
      layer[A[i].y].push_back(i);
    }
    int best = 0;
    M = 1;
    while(M<=2*n+2)
      M*=2;
    for(int i=1; i<=2*M; i++)
      T[i] = 0;
    set<int> S[maxn+1];
    for(int i=0; i<=2*n; i++)
    {
      for(int j=0; j<layer[i].size(); j++)
      {
        int c = A[layer[i][j]].c;
        int x = A[layer[i][j]].x;
        sit next = S[c].lower_bound(x);
        sit prev = next;
        if (next!=S[c].end() && *next==x)
          continue;
        if (prev!=S[c].begin())
          prev--;
        else
          prev = S[c].end();
        int res = (next!=S[c].end() ? query(*next-1) : T[1])
                - (prev!=S[c].end() ? query(*prev) : 0);
        best = max(best,res);
      }
      for(int j=0; j<layer[i].size(); j++)
      {
        int c = A[layer[i][j]].c;
        int x = A[layer[i][j]].x;
        S[c].insert(x);
        add(x);
      }
    }
    for(int c=1; c<=k; c++)
    {
      int prev = 0;
      for(sit t=S[c].begin(); t!=S[c].end(); t++)
      {
        best = max(best,query(*t-1)-prev);
        prev = query(*t);
      }
      best = max(best,n-prev);
    }
    printf("%d\n",best);
  }
}
