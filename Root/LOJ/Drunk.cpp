using namespace std;

#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "iostream"

#define SZ 20100

int vis[SZ], cycle, node;
vector <int> adj[SZ];
map <string, int> M;

void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        adj[i].clear();
        vis[i] = 0;
    }
    cycle = node = 0;
    M.clear();
}

void dfs_topsort(int n)
{
    if(vis[n] == 2 || cycle) return;
    if(vis[n] == 1)
    {
        cycle = 1;
        return;
    }
    int i, k;

    k = adj[n].size();
    vis[n] = 1;

    for(i=0;i<k;i++)
        dfs_topsort(adj[n][i]);

    vis[n] = 2;
    node++;
}

int main()
{
    int t = 0, test, n, m, i, j, k;
    char s1[15], s2[15];

    scanf("%d",&test);

    while(test--)
    {
        n = 0;
        scanf("%d",&m);
//        init(2*m);
        while(m--)
        {
            scanf("%s %s",s1,s2);
            if(M.find(s1) == M.end())
                M[s1] = n++;
            if(M.find(s2) == M.end())
                M[s2] = n++;
            adj[M[s1]].push_back(M[s2]);
        }
        for(i=0;i<n;i++)
        {
            dfs_topsort(i);
            if(cycle) break;
        }

        printf("Case %d: ",++t);
        if(cycle || node != n) printf("No\n");
        else printf("Yes\n");

        if(test) init(n);
    }

    return 0;
}
