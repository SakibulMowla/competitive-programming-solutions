#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 110
#define makeset(i,n) for(i=0;i<=n;i++) par[i] = i

struct data{ int a,b,c; };
bool comp(data a,data b){ return a.c < b.c; }
int par[SZ];
const int inf = 1000000000;

vector <data> v;

int find(int r)
{
    return par[r] == r ? r : par[r] = find(par[r]);
}

int mark[10010];

void MST(int t,int v1,int e)
{
    sort(v.begin(),v.end(),comp);
    int p,q,i,j,edges,mst2,option;
    edges = 0;
    for(i=0;i<e;i++)
        mark[i] = 0;
    for(i=0;i<v.size() && edges < v1-1;i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)continue;
        par[p] = q;
        mark[i] = 1; //marking that edge which i'm adding to MST
        edges++;
    }
    if(edges < v1-1)
    {
        printf("Case #%d : No way\n",t);
        return;
    }
    mst2 = inf;
    for(i=0;i<e;i++)
    {
        if(mark[i] == 1)
        {
            makeset(j,v1);
            option = 0;
            for(j=0;j<e;j++)
            {
                if(mark[j] == 1 && j!=i)
                {
                    par[find(v[j].a)] = find(v[j].b);
                    option += v[j].c;
                }
            }
            edges = 0;
            for(j=0;j<e && edges == 0;j++)
            {
                p = find(v[j].a);
                q = find(v[j].b);
                if(p!=q &&  mark[j] == 0)
                {
                    option += v[j].c;
                    edges = 1;
                }
            }
            if(option < mst2 && edges == 1)
                mst2 = option;
        }
    }
    if(mst2 == inf)
        printf("Case #%d : No second way\n",t);
    else
        printf("Case #%d : %d\n",t,mst2);
}

int main()
{
    data u;
    int i,v1,e,t,test;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d",&v1,&e);
        makeset(i,v1);
        v.clear();
        for(i=1;i<=e;i++)
        {
            scanf("%d %d %d",&u.a,&u.b,&u.c);
            v.push_back(u);
        }
        MST(t,v1,e);
    }

    return 0;
}
