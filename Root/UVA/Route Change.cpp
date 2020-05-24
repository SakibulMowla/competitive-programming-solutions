#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
#include "queue"
#include "map"

using namespace std;

#define SZ 255
#define inf 1<<28
#define SD(n) scanf("%d",&n)
#define FOR(i,n) for(i=0;i<n;i++)

typedef pair<int,int> pii;

struct data
{
    int city,dist;
    bool operator < ( const data& p ) const{
        return dist > p.dist;
    }
};

int n,m,c,k,d[SZ];
vector <int> edge[SZ] , cost[SZ];
priority_queue <data> Q;
pii P;
map <pii,int> M;

int dijkstra()
{
//    printf("n = %d m = %d c = %d k = %d\n",n,m,c,k);
    int i,j,ucost;
    data a,b;
    for(i=0;i<n;i++) d[i] = inf;
    while( !Q.empty() ) Q.pop();
    a.city = k;
    a.dist = 0;
    Q.push(a);
    d[k] = 0;
    while( !Q.empty() )
    {
        a = Q.top() , Q.pop();
//        printf("city = %d  cost = %d\n",a.city,a.dist);
        ucost = a.dist;
        if(a.city < c)
        {
            b.city = a.city + 1;
            P = make_pair(a.city , b.city);
            if(M.find(P) != M.end() && d[b.city] > d[a.city] + M[P])
            {
                b.dist = d[a.city] + M[P];
                d[b.city] = d[a.city] + M[P];
                Q.push(b);
            }
        }
        else
        for(i=0;i<edge[ a.city ].size();i++)
        {
            b.city = edge[ a.city ][i];
            b.dist = ucost + cost[a.city][i];
            if(d[b.city] > b.dist)
            {
                d[b.city] = b.dist;
                Q.push(b);
            }
        }
    }

    return d[c-1];
}


int main()
{
    int i,j,u,v,p;
//    freopen("1.txt","r",stdin);
    while(scanf("%d%d%d%d",&n,&m,&c,&k) == 4 && (n+m+c+k))
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&p);
            edge[u].push_back(v);
            edge[v].push_back(u);
            cost[u].push_back(p);
            cost[v].push_back(p);
            P = make_pair(u,v);
            M[P] = p;
            P = make_pair(v,u);
            M[P] = p;
        }
        printf("%d\n",dijkstra());
        M.clear();
        for(i=0;i<n;i++)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
