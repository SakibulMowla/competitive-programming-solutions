using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "stack"
#include "iostream"

#define SZ 10100

vector <int> adj[SZ];
stack <int> S;
int vis[SZ];

void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
        vis[i] = 0, adj[i].clear();
    while(!S.empty()) S.pop();
}

void dfs(int n)
{
    int i, k;
    k = adj[n].size();

    vis[n] = 1;

    for(i=0;i<k;i++)
        if(vis[adj[n][i]] == 0)
            dfs(adj[n][i]);
}

int main()
{
    int t=0, test, n, m, i, j, k;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d",&n,&m);
        init(n);

        while(m--)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
        }

        for(i=1;i<=n;i++)
            if(vis[i] == 0)
                dfs(i) , S.push(i);

        for(i=1;i<=n;i++)
            vis[i] = 0;
        k = 0;

        while(!S.empty())
        {
            j = S.top();
            S.pop();
            if(vis[j] == 0)
            {
                dfs(j);
                k++;
            }
        }

        printf("Case %d: %d\n",++t,k);
    }

    return 0;
}
/*
5 6

1 2
2 3
3 1
1 4
4 5
5 3

ans = 1
*/
