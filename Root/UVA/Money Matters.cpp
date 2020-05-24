#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
#define SZ 10010

int vis[SZ] , balance[SZ] , sum;
vector <int> adj[SZ];

void dfs(int n)
{
    vis[n] = 1;
    sum += balance[n];
    int i;
    for(i=0; i<adj[n].size(); i++)
        if(!vis[adj[n][i]])
            dfs(adj[n][i]);
}

int main()
{
    int test,i,j,n,m,possible;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        possible = 1;
        scanf("%d %d",&n,&m);
        for(i=0; i<n; i++)
        {
            scanf("%d",&balance[i]);
            adj[i].clear();
            vis[i] = 0;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&n,&j);
            adj[n].push_back(j);
            adj[j].push_back(n);
        }
        for(i=0; i<n; i++)
        {
            if(!vis[i])
            {
                sum = 0;
                dfs(i);
                if(sum != 0)
                {
                    possible = 0 ;
                    break;
                }
            }
        }
        if(possible) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
