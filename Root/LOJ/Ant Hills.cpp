using namespace std;

#include "stdio.h"
#include "vector"
#include "set"
#include "iostream"

#define SZ 10100

int T[SZ] , low[SZ] , tym , root;
vector <int> adj[SZ];

set <int> myset;

void init(int n)
{
    int i;
    myset.clear();
    for(i=1;i<=n;i++)
    {
        T[i] = 0;
        adj[i].clear();
    }
}

void artilary(int u,int p)
{
    int i,j,k,v,child;

    T[u] = low[u] = ++tym;
    k = adj[u].size();
    child = 0;

    for(i=0;i<k;i++)
    {
        v = adj[u][i];
        if(v == p) continue;

        if(T[v] == 0)
        {
            child++;
            artilary(v,u);
            low[u] = min(low[u] , low[v]);
            if(low[v] >= T[u] && u != root)
                myset.insert(u);
        }

        else if(T[v] < T[u])
            low[u] = min(low[u] , T[v]);

        if(u == root && child >= 2)
            myset.insert(u);
    }
}

int main()
{
    int test = 0, t , i, j , k , n ,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        init(n);

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }

        tym = 0;
        root = 1;

        artilary(1,-1);

        printf("Case %d: %d\n",++test,myset.size());
    }

    return 0;
}
