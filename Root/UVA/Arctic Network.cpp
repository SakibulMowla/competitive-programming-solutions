#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define SZ 510
#define Union(a,b) par[a] = b

struct edge{ int x,y; };
struct data{ int n1,n2; double dist; };
bool comp(data a,data b){ return a.dist < b.dist; }
int par[SZ];
vector <data> v;
vector <double> edge_list;

int find(int r)
{
    return par[r] == r ? par[r] : find(par[r]);
//    if(r != par[r])
//        par[r] = find(par[r]);
//    return par[r];
}

int makeset(int n)
{
    for(int i=0;i<=n;i++)
        par[i] = i;
}

double MST(int s,int p)
{
    edge_list.clear();
    sort(v.begin(),v.end(),comp);
    int i,size,a,b;
    for(i=0;i<v.size();i++)
    {
        a = find(v[i].n1);
        b = find(v[i].n2);
        if(a == b)continue;
        Union(a,b);
        edge_list.push_back(v[i].dist);
    }
    size = edge_list.size();
    return edge_list[size-s];
}

int main()
{
    data u;
    edge arr[SZ];
    int i,j,t,test,s,p;
    double ans;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        v.clear();
        scanf("%d %d",&s,&p);
        makeset(p);
        for(i=1;i<=p;i++)
            scanf("%d %d",&arr[i].x,&arr[i].y);
        for(i=1;i<p;i++)
            for(j=i+1;j<=p;j++)
            {
                u.n1 = i;
                u.n2 = j;
                u.dist = sqrt( pow(arr[i].x-arr[j].x , 2) + pow(arr[i].y-arr[j].y , 2) );
                v.push_back(u);
            }
        ans = MST(s,p);
        printf("%.2lf\n",ans);
    }

    return 0;
}
