#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 200010
#define makeset(n) for(i=0;i<=n;i++) par[i] = i

struct data
{
    int a,b,c;
};
bool comp(data p,data q)
{
    return p.c < q.c;
}

int par[SZ];
vector <data> v;

int find(int r)
{
    return r == par[r] ? r : par[r] = find(par[r]);
}

int MST(int n,int e)
{
    sort(v.begin(),v.end(),comp);
    int i,cost,p,q;
    cost = 0;
    for(i=0;i<v.size() && i<e-1;i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)continue;
        par[p] = q;
        cost += v[i].c;
    }
    return cost;
}

int main()
{
    data u;
    int n,e,i,total_cost,mst_cost,safe;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&n,&e) == 2)
    {
        if(n==0 && e==0)break;
        v.clear();
        makeset(n);
        total_cost = 0;
        for(i=0; i<e; i++)
        {
            scanf("%d %d %d",&u.a,&u.b,&u.c);
            total_cost += u.c;
            v.push_back(u);
        }
        mst_cost = MST(n,e);
        safe = total_cost - mst_cost;
        printf("%d\n",safe);
    }

    return 0;
}
