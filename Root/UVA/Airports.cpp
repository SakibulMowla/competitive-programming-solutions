#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 10010
#define Union(a,b) par[a] = b

int par[SZ];
struct data{ int n1,n2,dist; };
bool comp(data a,data b){ return a.dist < b.dist ; }
vector <data> v;
int total_cost,airports;

int find(int r)
{
    if(r != par[r])
        par[r] = find(par[r]);
    return par[r];
}

void makeset(int n)
{
    for(int i=1;i<=n;i++)
        par[i] = i;
}

void MST(int nodes,int air_cost)
{
    sort(v.begin(),v.end(),comp);
    int a,b,i,j,edges;
    edges = nodes - 1;
    j = 0;
    for(i=0 ; i < v.size() && j < edges && v[i].dist < air_cost ;i++)
    {
        a = find(v[i].n1);
        b = find(v[i].n2);
        if(a == b)continue;
        j++;
        Union(a,b);
        total_cost += v[i].dist;
    }
    for(i=1;i<=nodes;i++)
    {
        if(i == par[i])
        {
            airports++;
            total_cost += air_cost;
        }
    }
}

int main()
{
    data u;
    int t,test,i,n,m,a_cost;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d %d",&n,&m,&a_cost);
        v.clear();
        makeset(n);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&u.n1,&u.n2,&u.dist);
            v.push_back(u);
        }
        total_cost = airports = 0;
        MST(n,a_cost);
        printf("Case #%d: %d %d\n",t,total_cost,airports);
    }

    return 0;
}
