// CERC 2012
// Problem I: The Dragon and the knights
// Model solution, O(n^2 + nm)
// Author: Lech Duraj

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 201;
const int maxm = 50010;

int A[maxn],B[maxn],C[maxn],R[maxn];
long long X[maxm],Y[maxm];


int main()
{
  int TT;
  scanf("%d",&TT);
  while(TT--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
      scanf("%d%d%d",&A[i],&B[i],&C[i]);
    int regions = 1;
    for(int i=0; i<n; i++)
    {
      regions++;
      for(int j=0; j<i; j++)
        if (A[i]*B[j]!=A[j]*B[i])
          regions++;
    }
    for(int i=0; i<m; i++)
      scanf("%Ld%Ld",&X[i],&Y[i]);
    vector< vector<int> > G;
    G.resize(1);
    for(int i=0; i<m; i++)
      G[0].push_back(i);
    for(int i=0; i<n; i++)
    {
      int r = G.size();
      for(int j=0; j<r; j++)
      {
        vector<int> v[2];
        for(int k=0; k<G[j].size(); k++)
        {
          int q = G[j][k];
          if (A[i]*X[q]+B[i]*Y[q]+C[i]>0)
            v[0].push_back(q);
          else
            v[1].push_back(q);
        }
        if (v[0].empty())
          swap(v[0],v[1]);
        G[j] = v[0];
        if (!v[1].empty())
          G.push_back(v[1]);
      }
    }
    fprintf(stderr,"Regions: %d, posts: %d.\n",regions,G.size());
    printf(regions==G.size() ? "PROTECTED\n" : "VULNERABLE\n");
  }
}
