#include "stdio.h"
#include "string.h"
#include "map"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

#define SZ 10010

int par[SZ];

struct data
{
    int x,y,d;
};

bool comp(data p,data q)
{
    return p.d < q.d;
}

map <int , int> M;
vector <data> list;

void init(int n)
{
    int i;
    M.clear();
    list.clear();
    for(i=0;i<=n;i++)
        par[i] = i;
}

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void Union(int a,int b)
{
    par[a] = b;
}

int MST(int n)
{
    int i,u,v,k=1,cost=0;
    for(i=0;k!=n;i++)
    {
        u = list[i].x;
        v = list[i].y;
        u = find(u);
        v = find(v);
        if(u != v)
        {
//            printf("%d -> %d .... %d\n",list[i].x,list[i].y,list[i].d);
            Union(u,v);
            cost += list[i].d;
            k++;
        }
    }
    return cost;
}

int main()
{
    int t,n,m,i,k;
    data u;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        init(n);
        k = 0;
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u.x,&u.y,&u.d);
            if(M.find(u.x) == M.end()) M[u.x] = ++k;
            if(M.find(u.y) == M.end()) M[u.y] = ++k;
            u.x = M[u.x];
            u.y = M[u.y];
            list.push_back(u);
        }
        sort(list.begin(),list.end(),comp);
        printf("%d\n",MST(n));
    }
    return 0;
}
