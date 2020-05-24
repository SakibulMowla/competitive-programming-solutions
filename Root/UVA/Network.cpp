using namespace std;

#include "stdio.h"
#include "string.h"
#include "vector"
#include "map"
#include "stdlib.h"

#define SZ 110

int T[SZ] , low[SZ] , tym , root;
vector <int> adj[SZ];
map <int , int> M;

void init(int n)
{
    int i;
    M.clear();
    for(i=0;i<=n;i++)
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
                M[u] = 1;
        }

        else if(T[v] < T[u])
            low[u] = min(low[u] , T[v]);

        if(u == root && child >= 2)
            M[u] = 1;
    }

}


int main()
{
    int i,j,k,n,m;
    char arr[1000] , *str;
    while(scanf("%d",&n) == 1 && n)
    {
        init(n);
        m = 0;
        while(scanf(" %[^\n]",arr) == 1)
        {
            if(strcmp(arr,"0") == 0) break;
            str = strtok(arr," ");
            i = atoi(str);

            str = strtok(NULL," ");
            while(str)
            {
                j = atoi(str);

                adj[i].push_back(j);
                adj[j].push_back(i);
                str = strtok(NULL," ");
            }
        }

        tym = 0;

        for(i=1;i<=n;i++)
        {
            root = i;
            artilary(i,-1);
        }

        printf("%d\n",M.size());
    }

    return 0;
}
