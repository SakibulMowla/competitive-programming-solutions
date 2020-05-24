#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"
#include "vector"
#include "queue"

using namespace std;


#define SZ 210

struct data
{
    int x,y,d;
    data(){}
    data(int a,int b,int c)
    {
        x = a , y = b , d = c;
    }
    bool operator < (const data&z) const
    {
        return d < z.d;
    }
};


data V[SZ];
int par[SZ] , cyc[SZ] , edge;

void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
        cyc[i] = 0 , par[i] = i;
}

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void Union(int a,int b)
{
    if(cyc[a] > cyc[b]) par[b] = a;
    else par[a] = b;
    if(cyc[a] == cyc[b]) cyc[b]++;
}

int MST(int n)
{
    int i,k,p,q,cost=0,cnt=0;
    data u;
    init(n);
    int d = -1;
    for(i=0;i<edge;i++)
    {
        u = V[i] ;
        p = find(u.x) ;
        q = find(u.y) ;
//        printf("node = %d node = %d  cost = %d\n",u.x,u.y,u.d);
        if(p != q)
        {
            cnt++;
            Union(p,q);
            cost += u.d;
        }
        else d=i;
    }
//    printf("cnt = %d\n",cnt);
    if(d!=-1) V[d]=V[--edge];
    if(cnt != n-1) return -1;
    return cost;
}

int main()
{
    int test=0,t,i,j,k,p,n,m,q;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",++test);

        edge = 0;
        while(q--)
        {
//            Q1 = Q2;
            scanf("%d %d %d",&j,&k,&p);

            V[edge].x = j ;
            V[edge].y = k ;
            V[edge].d = p ;
            edge++;
            stable_sort(V,V+edge);
//            Q2.push( data(j,k,p) );
            printf("%d\n",MST(n));
        }

    }

    return 0;
}
