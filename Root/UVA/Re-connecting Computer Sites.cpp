#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define SZ 1000010
#define Union(a,b) par[find(a)] = find(b)

struct data
{
    int n1,n2,c;
};

int par[SZ];
vector <data> v;

bool comp(data a,data b)
{
    return a.c < b.c;
}

void makeset(int n)
{
    int i;
    for(i=1;i<=n;i++)
        par[i] = i;
}

int find(int r)
{
    if(par[r] != r)
        par[r] = find(par[r]);
    return par[r];
}

int MST(int nodes)
{
    sort(v.begin(),v.end(),comp);
    int i,cost,a,b;
    cost = 0;
    for(i=0;i<v.size();i++)
    {
        a = v[i].n1;
        b = v[i].n2;
        if(find(a) == find(b))
            continue;
        Union(a,b);
        cost += v[i].c;
    }
    return cost;
}

int main()
{
    int i,j,nodes,ans,k,m,test;
    data u;
    test = 0;
    while(scanf("%d",&nodes) == 1)
    {
        if(test)printf("\n");
        test = 1;
        v.clear();
        makeset(nodes);
        for(i=1;i<nodes;i++)
        {
            scanf("%d %d %d",&u.n1,&u.n2,&u.c);
            v.push_back(u);
        }
        ans = MST(nodes);
        printf("%d\n",ans);
        v.clear();
        scanf("%d",&k);
        for(i=1;i<=k;i++)
        {
            scanf("%d %d %d",&u.n1,&u.n2,&u.c);
            v.push_back(u);
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&u.n1,&u.n2,&u.c);
            v.push_back(u);
        }
        makeset(m);
        ans = MST(m);
        printf("%d\n",ans);
    }

    return 0;
}
