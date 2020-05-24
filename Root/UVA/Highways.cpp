#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define Union(a,b) par[a] = b
#define SZ 800

int par[SZ];
struct nodes{ int p1,p2; };
struct data{ int a,b; double dist; };
bool comp(data p,data q){ return p.dist < q.dist; };

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

void MST(int nodes)
{
    sort(v.begin(),v.end(),comp);
    int i,count,p,q;
    count = 0;
    for(i=0;i<v.size();i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)continue;
        Union(p,q);
        printf("%d %d\n",v[i].a,v[i].b);
        count++;
    }
    if(count == 0)
        printf("No new highways need\n");
}

int main()
{
    int t,test,i,j,n,m,a,b;
    data u;
    nodes arr[SZ];
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        makeset(n);
        v.clear();
        for(i=1;i<=n;i++)
            scanf("%d %d",&arr[i].p1,&arr[i].p2);
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            a = find(a);
            b = find(b);
            Union(a,b);
        }
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                u.a = i;
                u.b = j;
                u.dist = sqrt( pow(arr[i].p1 - arr[j].p1 , 2) + pow(arr[i].p2 - arr[j].p2 , 2) );
                v.push_back(u);
            }
        }
        MST(n);
        if(t<test)
            printf("\n");
    }
    return 0;
}
