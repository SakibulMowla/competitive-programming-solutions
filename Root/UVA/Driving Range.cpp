#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 1000010
#define makeset(n)  for(i=0;i<=n;i++) par[i] = i

struct data { int a,b,c; };
bool comp( data p,data q ){ return p.c < q.c; }

int par[SZ];
vector <data> v;

int find(int r)
{
    return par[r] == r ? r : par[r] = find(par[r]);
}

void MST(int n,int e)
{
    sort(v.begin(),v.end(),comp);
    int p,q,i,edges,minimax;
    minimax = 0;
    edges = 0;
    for(i=0;i<v.size();i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)continue;
        par[p] = q;
        edges++;
        if(v[i].c > minimax)
            minimax = v[i].c;
    }
    if(edges == n-1)
        printf("%d\n",minimax);
    else
        printf("IMPOSSIBLE\n");
}

int main()
{
    data u;
    int n,e,i;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&n,&e) == 2)
    {
        if(n==0 && e==0)break;
        makeset(n);
        v.clear();
        for(i=0;i<e;i++)
        {
            scanf("%d %d %d",&u.a,&u.b,&u.c);
            v.push_back(u);
        }
        MST(n,e);
    }
    return 0;
}
