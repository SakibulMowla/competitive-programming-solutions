#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define Union(a,b) par[a] = b
#define SZ 410

struct data
{
    int a,b,cost;
};
bool comp(data a,data b)
{
    return a.cost < b.cost;
}

int par[SZ];
vector <data> v;

int find(int r)
{
    if(r != par[r])
        par[r] = find(par[r]);
    return par[r];
}

void makeset(int n)
{
    for(int i=1; i<=n; i++)
        par[i] = i;
}

int MST(int nodes)
{
    sort(v.begin(),v.end(),comp);
    int i,edges,a,b,dist;
    edges = nodes - 1;
    dist = 0;
    for(i=0;i<v.size() && edges;i++)
    {
        a = find(v[i].a);
        b = find(v[i].b);
        if(a == b)
            continue;
        Union(a,b);
        dist += v[i].cost;
        edges--;
    }
    if(edges)
        return -1;

    return dist;
}

int main()
{
    int s,c,i,ans,dist;
    data u;
    char arr[100],arr1[100];
    map <string , int> m;
    while(scanf("%d %d",&s,&c) == 2)
    {
        if(s==0 && c==0)break;
        m.clear();
        v.clear();
        makeset(s);
        for(i=1;i<=s;i++)
        {
            scanf("%s",arr);
            m[arr] = i;
        }
        for(i=1;i<=c;i++)
        {
            scanf("%s %s %d",arr,arr1,&dist);
            u.a = m[arr];
            u.b = m[arr1];
            u.cost = dist;
            v.push_back(u);
        }
        scanf(" %s",arr);
        ans = MST(s);
        if(ans == -1)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
    }

    return 0;
}
