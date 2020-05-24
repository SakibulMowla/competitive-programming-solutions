#include <bits/stdc++.h>

using namespace  std;

#define sz(x) (int)x.size()
#define SZ 100010

typedef long long ll;
const ll inf = 1LL<<28;

vector <ll> adj[SZ];

ll sibling[SZ][2], distUp[SZ], distDown[SZ];
bool mark[SZ];

void dfs_down(ll node,ll par)
{
    ll i, j, k;

    k = sz(adj[node]);

    distDown[node] = mark[node] ? 0 :  -inf;
    sibling[node][0] = sibling[node][1] = -inf;

    for(i=0;i<k;i++)
    {
        j = adj[node][i];
        if(j == par) continue;

        dfs_down(j, node);
        if(distDown[j] > sibling[node][0])
        {
            sibling[node][1] = sibling[node][0];
            sibling[node][0] = distDown[j];
        }
        else if(distDown[j] > sibling[node][1])
            sibling[node][1] = distDown[j];

        distDown[node] = max(distDown[node] , distDown[j] + 1);
    }
}

void dfs_up(ll node,ll par)
{
    if(par == -1)
        distUp[node] = mark[node] ? 0 : -inf;
    else
    {
        if(sibling[par][0] != distDown[node])
            distUp[node] = sibling[par][0] + 2;
        else distUp[node] = sibling[par][1] + 2;
        if(distUp[node] < distUp[par] + 1)
            distUp[node] = distUp[par] + 1;
    }

    if(mark[node])
        distUp[node] = max(distUp[node], 0LL);

    ll i, j, k;

    k = sz(adj[node]);

    for(i=0;i<k;i++)
    {
        j = adj[node][i];
        if(j == par) continue;
        dfs_up(j, node);
    }
}

int main()
{
    ll n, m, d, i, j, k;

    while(scanf("%I64d %I64d %I64d",&n,&m,&d) == 3)
    {
        for(i=0; i<m; i++)
        {
            scanf("%I64d",&j);
            mark[j] = 1;
        }

        for(i=0; i<n-1; i++)
        {
            scanf("%I64d %I64d",&j,&k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }

        dfs_down(1, -1);
        dfs_up(1, -1);

        k = 0;

        for(i=1;i<=n;i++)
            if(distDown[i] <= d && distUp[i] <= d)
                k++;

        printf("%I64d\n",k);
    }

    return 0;
}

