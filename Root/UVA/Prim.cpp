#include "bits/stdc++.h"
using namespace std;

#define SZ 12
#define SZ1 27

struct data
{
    int u, v, w, m;
};

data road[SZ1];

bool comp(data p, data q)
{
    return p.w < q.w;
}

int par[SZ], cnt[SZ];

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

int mst(int n,int m)
{
    int x, y, i, k, tot, yes;
    tot = k = yes = 0;
    for(i=0;i<=n;i++)
        par[i] = i, cnt[i] = 1;
    for(i=0;i<m;i++)
    {
        x = find(road[i].u);
        y = find(road[i].v);
        if(x == y) continue;
        par[x] = y;
        tot += road[i].w;
        cnt[y] += cnt[x];
        road[i].m = 1;
        if(cnt[y] == n) yes = 1;
    }
    if(!yes) return -1;
    k = yes = 0;
    for(i=0;i<=n;i++)
        par[i] = i, cnt[i] = 1;
    for(i=0;i<m;i++)
    {
        if(road[i].m) continue;
        x = find(road[i].u);
        y = find(road[i].v);
        if(x == y) continue;
        par[x] = y;
        tot += road[i].w;
        cnt[y] += cnt[x];
        road[i].m = 0;
        if(cnt[y] == n) yes = 1;
    }
    if(!yes) return -1;
    return tot;
}

int main()
{
    int n, m, i;

    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&road[i].u,&road[i].v,&road[i].w);
            road[i].m = 0;
        }
        sort(road,road+m,comp);
        n = mst(n,m);
        if(n == -1) printf("No way!\n");
        else printf("%d\n",n);
    }

    return 0;
}
