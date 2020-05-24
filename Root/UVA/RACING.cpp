#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 10010
#define makeset(n) for(i=0;i<=n;i++) par[i] = i

struct data { int a,b,c; };
bool comp(data p,data q){ return p.c > q.c; }

int par[SZ];
vector <data> v;

int find(int r)
{
    return par[r] == r ? r : par[r] = find(par[r]);
}

int MST()
{
    sort(v.begin(),v.end(),comp);
    int p,q,i,cost;
    cost = 0;
    for(i=0;i<v.size();i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)
            cost += v[i].c;
        else
            par[p] = q;
    }
    return cost;
}

int main()
{
    data u;
    int i,n,e,test;
//    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&e);
        makeset(n);
        v.clear();
        for(i=0;i<e;i++)
        {
            scanf("%d %d %d",&u.a,&u.b,&u.c);
            v.push_back(u);
        }
        printf("%d\n",MST());
    }
    scanf("%d",&test);

    return 0;
}
