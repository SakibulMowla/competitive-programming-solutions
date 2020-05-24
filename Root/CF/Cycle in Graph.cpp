#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace  std;
typedef pair <int,int> pii;

#define SZ 100010

vector <int> edge[SZ];
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
    if(cycle.size() >= k+1 && M.find( make_pair(s, cycle[0] ) ) != M.end() )
    {
        printf("%d\n",cycle.size());
        printf("%d",cycle[0]);

        for(i=1;i<cycle.size();i++) printf(" %d",cycle[i]);
        printf("\n");
        found = true;
        return;
    }
    for(i=0;i<edge[s].size();i++)
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
    while(scanf("%d %d %d",&n,&m,&k) == 3)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
            p = make_pair(u,v);
            M[p] = 1;
            p = make_pair(v,u);
            M[p] = 1;
        }
        found = false;
        for(i=1;i<=n;i++)
        {
            memset(taken,0,sizeof(taken));
            if(found == true) break;
            cycle.clear();
            cycle.push_back(i);
            taken[i] = 1;
            bctk(i);
        }
    }

    return 0;
}
