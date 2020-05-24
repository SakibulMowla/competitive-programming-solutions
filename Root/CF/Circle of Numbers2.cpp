#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace  std;
typedef pair <int,int> pii;
#define inf 1<<28
#define SD(n) scanf("%d",&n)
#define SS(n) scanf("%s",n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 200010

vector <int> edge[SZ] , edge1[SZ];
vector <int> cycle;
int n,m,k;
pii p,q;
map<pii,int> M;
bool found;
bool taken[SZ];

void bctk(int s)
{
    int i,u,v;
    if(found) return;
    if(cycle.size() == n && M.find( make_pair(s, cycle[0] ) ) != M.end() )
    {
        printf("%d",cycle[0]);
        for(i=1; i<cycle.size(); i++) printf(" %d",cycle[i]);
        printf("\n");
        found = true;
        return;
    }
    for(i=0; i<edge[s].size(); i++)
    {
        u = edge[s][i];
        if(taken[u] == 0)
        {
            taken[u] = 1;
            cycle.push_back(u);
            bctk(u);
            cycle.pop_back();
            taken[u] = 0;
        }
    }
}


int main()
{
    int i,j,u,v,s;
    while(scanf("%d",&n) == 1)
    {
        for(i=0; i<2*n; i++)
        {
            scanf("%d %d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
            p = make_pair(u,v);
            M[p] = 1;
            q = make_pair(u,v);
            M[q] = 1;
        }
        found = false;

        memset(taken,0,sizeof(taken));

        cycle.clear();
        cycle.push_back(1);
        taken[1] = 1;
        bctk(1);
        if(found == false) printf("-1\n");
    }


    return 0;
}
