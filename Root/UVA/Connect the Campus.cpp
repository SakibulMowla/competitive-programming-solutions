#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 800
#define Union(a,b) par[a] = b

int par[SZ];
struct edge{ int x,y; };
struct data{ int a,b;double dist; };
bool comp(data a,data b){ return a.dist < b.dist; }
vector <data> v;

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

double MST(int nodes)
{
    sort(v.begin(),v.end(),comp);
    int i,j,k,l,p,q;
    double cost = 0;
    for(i=0;i<v.size();i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)continue;
        Union(p,q);
        cost += v[i].dist;
    }

    return cost;
}


int main()
{
    data u;
    edge arr[SZ];
    int i,j,n,m,a,b,p,q;
    double ans;
    while(scanf("%d",&n) == 1)
    {
        v.clear();
        for(i=1;i<=n;i++)
            scanf("%d %d",&arr[i].x,&arr[i].y);
        makeset(n);
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            p = find(a);
            q = find(b);
            par[p] = q;
        }
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                u.a = i;
                u.b = j;
                u.dist = sqrt( pow(arr[i].x-arr[j].x,2) + pow(arr[i].y-arr[j].y,2) );
                v.push_back(u);
            }
        }

        ans = MST(n);
        printf("%.2lf\n",ans);
    }

    return 0;
}
