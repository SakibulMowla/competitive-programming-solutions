// CERC 2012
// Problem D: Non-boring sequences
// Alternative model solution.
// Author: Lech Duraj

#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 200*1000;

int M;

int low[4*maxn+10],val[4*maxn+10];

void rec_add(int node, int p, int q, int start, int end, int x)
{
  if (p==start && q==end)
  {
    val[node]+=x;
    low[node]+=x;
    return;
  }
  int mid = (start+end)/2;
  if (p<=mid)
    rec_add(2*node,p,min(q,mid),start,mid,x);
  if (q>=mid+1)
    rec_add(2*node+1,max(p,mid+1),q,mid+1,end,x);
  low[node] = val[node]+min(low[2*node],low[2*node+1]);
}

void add(int p, int q, int x)
{
  if (p<=q)
    rec_add(1, p+M, q+M, M, 2*M-1, x);
}

int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int n;
    scanf("%d",&n);
    M = 1;
    while(M<=n)
      M*=2;
    for(int i=1; i<=2*M; i++)
    {
      val[i] = low[i] = 0;
    }
    add(0,M-1,1);
    map<int,int> P,L;
    bool ok = true;
    for(int i=0; i<n; i++)
    {
      int a,last,prev;
      add(i,i,-1);
      scanf("%d",&a);
      if (L.find(a)!=L.end())
        last = L[a];
      else
        last = -1;
      if (P.find(a)!=P.end())
        prev = P[a];
      else
        prev = -1;
      add(prev+1,last,-1);
      add(last+1,i,1);
      P[a] = last;
      L[a] = i;
      if (low[1]==0)
        ok = false;
    }
    printf(ok ? "non-boring\n" : "boring\n");
  }
}
