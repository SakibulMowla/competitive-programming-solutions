#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define inf 1<<28

int learning[110] , final , total;

vector <int> adj[110];

void recurse(int n)
{
    if(adj[n].size() == 0)
    {
        final = n;
        return;
    }
    int i,j,maxim,next;
    maxim = -inf;
    for(i=0;i<adj[n].size();i++)
    {
        if(learning[adj[n][i]] > maxim)
        {
            maxim = learning[adj[n][i]];
            next = adj[n][i];
        }
    }
    total += learning[next];
    recurse(next);
}

int main()
{
    int i,j,m,n,t,test;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        memset(learning,0,sizeof(learning));
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            learning[i] = j;
            adj[i].clear();
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&n,&j);
            adj[n].push_back(j);
        }
        total = learning[0];
        final = 0;
        recurse(0);
        printf("Case %d: %d %d\n",t,total,final);
    }

    return 0;
}
