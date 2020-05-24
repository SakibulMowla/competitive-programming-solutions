#include "stdio.h"
#include "string.h"
#include "stack"
#include "queue"
#include "vector"
#include "iostream"
using namespace std;
#define SZ 3010

int dist[SZ] , GP , parr[SZ] , N;
bool visited[SZ] , found;
vector <int> adj[SZ];
queue <int> Q;

void init(int n)
{
    int i;
    for(i=0; i<=n; i++)
    {
        parr[i] = i;
        adj[i].clear();
        visited[i] = false;
    }
    while(!Q.empty()) Q.pop();
}

void BFS()
{
    int u,i,j,k;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        k = adj[u].size();
        for(i=0; i<k; i++)
        {
            j = adj[u][i];
//            printf("j = %d\n",j);
            if(visited[j] == false)
            {
                visited[j] = true;
                Q.push(j);
                dist[j] = dist[u] + 1;
            }
        }
    }
}

void dfs(int par,int n)
{
//    printf("p = %d n = %d\n",par,n);
    if(found) return;

    if(visited[n] == 1)
    {
        memset(visited,false,sizeof(visited));
        int i;
        i = parr[n];
//        printf("i = %d\n",i);
        visited[i] = 1;
        Q.push(i);
        dist[i] = 0;
        while(i != n)
        {
            i = parr[i];
//            printf("i = %d\n",i);
            visited[i] = 1;
            Q.push(i);
            dist[i] = 0;
        }
        found = 1;
        return;
    }
//    if(visited[n] == 1) return;
    visited[n] = 1;
    int i,j,k;
    k = adj[n].size();
    for(i=0; i<k; i++)
    {
        j = adj[n][i];
        if(par != j)
            parr[j] = n , dfs(n,j);
    }
}

int main()
{
    int n,i,j,k;
    while(scanf("%d",&n) == 1)
    {
        N = n;
        init(n);
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        found = 0;
        for(i=1; i<=n; i++)
        {
            if(found) break;
//            memset(visited,false,sizeof(bool)*(n+5));
            GP = i;
            dfs(-1,i);
        }
//        printf("yes\n");
        BFS();
        for(i=1; i<=n; i++)
        {
            if(i-1) printf(" ");
            printf("%d",dist[i]);
        }
        printf("\n");
    }

    return 0;
}
