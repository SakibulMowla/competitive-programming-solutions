#include "stdio.h"
#include "string.h"
#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 110
const int inf = 1000000000;
int par[SZ];
struct data{ int a,b,c; };
bool comp(data a,data b){ return a.c < b.c; };

vector <data> v;

int find (int r)
{
    return par[r] == r ? r : par[r]=find(par[r]);
}

int makeset(int n)
{
    for(int i=1;i<=n;i++)
        par[i] = i;
}

int mark[10010];

void MST(int n,int m)
{
    sort(v.begin(),v.end(),comp);
    int i,j,p,q,mst1,mst2,option,edges;
    mst1 = 0;
    edges = 0;
    for(i=1;i<=m;i++)
        mark[i] = 0;
    for(i=0;i<v.size() && edges<n-1;i++)
    {
        p = find(v[i].a);
        q = find(v[i].b);
        if(p == q)continue;
        par[p] = q;
        mst1 += v[i].c;
        edges++;
        mark[i+1] = 1; //marking that edge which i'm adding to mst
    }
    mst2 = inf;
    for(i=1;i<=m;i++)
    {
        if(mark[i] == 1)
        {
            makeset(n);
            option = 0;
            for(j=1;j<=m;j++)
            {
                if(mark[j]==1 && j!=i)
                {
                    option += v[j-1].c;
                    par[find(v[j-1].a)] = find(v[j-1].b);
                }
            }
            edges = 0;
            for(j=1;j<=m && edges == 0;j++)
            {
                p = find(v[j-1].a);
                q = find(v[j-1].b);
                if(mark[j] == 0 && p != q)
                {
                    option += v[j-1].c;
                    edges = 1;
                }
            }
        }
        if(edges == 1 && option < mst2)
            mst2 = option;
    }
    printf("%d %d\n",mst1,mst2);
}

int main()
{
    data u;
    int t,test,i,j,k,l,n,m;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d %d",&n,&m);
        makeset(n);
        v.clear();
        for(i=1;i<=m;i++)
        {
           scanf("%d %d %d",&u.a,&u.b,&u.c);
           v.push_back(u);
        }
        MST(n,m);
    }

    return 0;
}
