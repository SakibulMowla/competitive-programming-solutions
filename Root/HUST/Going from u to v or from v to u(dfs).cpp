
#include "stdio.h"
#include "vector"
#include "stack"
#include "iostream"

using namespace std;

#define SZ 1010

vector <int> adj[SZ];
int col[SZ], cnt;

void dfs(int u)
{
    col[u] = 1;
    cnt++;

    int i, j, k;

    k = adj[u].size();

    for(i=0; i<k; i++)
    {
        j = adj[u][i];
        if(col[j]) continue;
        dfs(j);
    }

    return;
}

int main()
{
    int t, i, j, k, n, m;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            col[i] = 0;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        cnt = 0;
        dfs(1);
        if(cnt == n) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
