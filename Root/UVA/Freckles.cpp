#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define SZ 110
#define Union(a,b) par[find(a)] = find(b)

struct vertex
{
    double x,y;
};

struct data
{
    int p1,p2;
    double dist;
};

bool comp(data a,data b)
{
    return a.dist < b.dist;
}

vector <data> v;

int par[SZ];

int find(int r)
{
    if(r != par[r])
        par[r] = find(par[r]);
    return par[r];
}

void makeset(int n)
{
    for (int i=1; i<=n; i++ )
        par[i] = i;
}

double MST(int nodes)
{
    sort(v.begin(),v.end(),comp);
    int i,a,b;
    double cost = 0;
    for(i=0; i<v.size(); i++)
    {
        a = v[i].p1;
        b = v[i].p2;
        if(find(a) == find(b))continue;
        Union(a,b);
        cost += v[i].dist;
    }
    return cost;
}

int main()
{
    vertex arr[SZ];
    int t,test,i,j,k,l,nodes;
    double d;
    data u;
    scanf("%d",&test);
    for (t=0; t<test ; t++ )
    {
        v.clear();
        scanf("%d",&nodes);
        makeset(nodes);
        for(i=1; i<=nodes; i++)
            scanf("%lf %lf",&arr[i].x,&arr[i].y);
        for(i=1; i<nodes; i++)
        {
            for(j=i+1; j<=nodes; j++)
            {
                d = sqrt((arr[i].x-arr[j].x) * (arr[i].x-arr[j].x) + (arr[i].y-arr[j].y) * (arr[i].y-arr[j].y));
                u.p1 = i;
                u.p2 = j;
                u.dist = d;
                v.push_back(u);
            }
        }
        d = MST(nodes);
        if(t)printf("\n");
        printf("%.2lf\n",d);
    }

    return 0;
}
