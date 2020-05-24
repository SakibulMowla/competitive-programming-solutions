using namespace  std;

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

typedef long long ll;


#define SZ 40500

int n , P[SZ][20] , dist[SZ][20] , L[SZ] , col[SZ];

struct data
{
    int to,cost;
    data(int a,int b)
    {
        to = a ;
        cost = b;
    }
};

vector <data> edge[SZ];

void init()
{
    int i;
    for(i=0; i<=n; i++)
    {
        edge[i].clear();
        col[i] = 0;
    }
}

void DFS(int source)
{
    col[source] = 1;
    int i,j,k;
    k = edge[source].size();
    for(i=0;i<k;i++)
    {
        j = edge[source][i].to;
        if(col[j] == 0)
        {
            L[j] = L[source] + 1;
            P[j][0] = source;
            dist[j][0] = edge[source][i].cost;
            DFS(j);
        }
    }
}

void process()
{
    int i,j,h,lev;
    for(h=1; (1LL<<h)<=n; h++);
    --h;
    for(i=0; i<=n; i++)
        for(j=0; j<=h; j++)
            P[i][j] = -1 , dist[i][j] = 0;

    L[1] = 0;
    DFS(1);

    for(lev=1; lev<=h; lev++)
        for(i=1; i<=n; i++)
            if(P[i][lev-1] != -1)
            {
                dist[i][lev] = dist[i][lev-1] + dist[ P[i][lev-1] ][lev-1];
                P[i][lev] = P[ P[i][lev-1] ][lev-1];
            }
}

int query(int p, int q)
{
    if(L[p] < L[q]) swap(p,q);
    int i,h,tot=0;
    for(h=1; (1LL<<h)<=L[p]; h++);
    --h;

    for(i=h; i>=0; i--)
    {
        if(L[p] - (1LL<<i) >= L[q])
        {
            tot += dist[p][i];
            p = P[p][i];
        }
    }

    if(p == q) return tot;

    for(i=h; i>=0; i--)
    {
        if(P[p][i] != -1 && P[q][i] != -1 && P[p][i] != P[q][i])
        {
            tot += dist[p][i] + dist[q][i];
            p = P[p][i];
            q = P[q][i];
        }
    }

    tot += dist[p][0] + dist[q][0];

    return tot;
}

int main()
{
    int i,j,k,m,q,t,co;
    cin >> t;
    while(t--)
    {
//        cin >> n >> q;
        scanf("%d %d",&n,&q);
        init();
        for(i=0; i<n-1; i++)
        {
//            cin >> j >> k >> co;
            scanf("%d %d %d",&j,&k,&co);
            edge[j].push_back( data(k,co) );
            edge[k].push_back( data(j,co) );
        }
        process();
        while(q--)
        {
//            cout << "q = " << q << "\n";
//            printf("q = %d\n",q);
//            cin >> j >> k;
            scanf("%d %d",&j,&k);
            printf("%d\n",query(j,k));
            if(q == 0LL) break;
//            cout << query(j,k) << "\n";
        }
//        cout << "\n"; // printing newline gives WA
    }

    return 0;
}
