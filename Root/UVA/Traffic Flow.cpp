// maximin MST

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 110
#define Union(a,b) par[a] = b

int par[SZ];
struct data{ int a,b,dist; };
bool comp(data a,data b){ return a.dist > b.dist; }
vector <data> v;

int find(int r)
{
    if(r != par[r])
        par[r] = find(par[r]);
    return par[r];
}

void makeset(int n)
{
    for(int i=0;i<n;i++)
        par[i] = i;
}

double MST(int n)
{
    sort(v.begin(),v.end(),comp);
    int i,p,q,d;
    d = 0;
    int res = 100000000;
    for(i=0;i<v.size() && d<n-1;i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)continue;
        Union(p,q);
        if(v[i].dist < res)
            res = v[i].dist;
    }

    return res;
}


int main()
{
    data u;
    int i,n,m,t,test,ans;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d",&n,&m);
        v.clear();

        makeset(n);

        for(i=1;i<=m;i++)
            scanf("%d %d %d",&u.a,&u.b,&u.dist),v.push_back(u);

        ans = MST(n);
        printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}

