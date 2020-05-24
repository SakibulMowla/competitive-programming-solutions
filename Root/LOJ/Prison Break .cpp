#include "bits/stdc++.h"
using namespace std;

const int inf = 1e9;
#define SZ 110

inline void read (int &n)
{
    n = 0;
    int i = getchar_unlocked();

    while (i < '0' || i > '9')
        i = getchar_unlocked();

    while (i >= '0' && i <= '9')
    {
        n = (n << 3) + (n << 1) + i - '0';
        i = getchar_unlocked();
    }
}

struct data
{
    int to, gas, cost;
    bool operator < (const data &x) const
    {
        return cost > x.cost;
    }
    data() {}
    data(int a,int b,int c)
    {
        to = a;
        gas = b;
        cost = c;
    }
};

vector <data> adj[SZ];
priority_queue <data> pq;
int dist[SZ][SZ], price[SZ];

int dijkstra(int n, int start, int end, int cap)
{
    while(!pq.empty()) pq.pop();

    int i, j, k, w;
    data u;

    for(i=0; i<=n; i++)
        for(j=0; j<=cap; j++)
            dist[i][j] = inf;

    dist[start][0] = 0;
    pq.push( data(start, 0, 0) );

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        if(u.to == end)
            return u.cost;

        if(u.gas+1 <= cap && u.cost+price[u.to] < dist[u.to][u.gas+1])
        {
            dist[u.to][u.gas+1] = u.cost + price[u.to];
            pq.push( data(u.to, u.gas+1, u.cost+price[u.to]) );
        }

        k = adj[u.to].size();

        for(i=0; i<k; i++)
        {
            j = adj[u.to][i].to;
            w = adj[u.to][i].cost;
            if(u.gas < w) continue;
            if(dist[j][u.gas-w] > u.cost)
            {
                dist[j][u.gas-w] = u.cost;
                pq.push( data(j, u.gas-w, u.cost) );
            }
        }
    }

    return -1;
}

int main()
{
    int test=0, t, i, j, k, l, n, m, q;

    read(t);

    while(t--)
    {
        read(n);
        read(m);

        for(i=0; i<n; i++)
            adj[i].clear(), read(price[i]);

        for(i=0; i<m; i++)
        {
            read(j);
            read(k);
            read(l);
            adj[j].push_back( data(k, 0, l) );
            adj[k].push_back( data(j, 0, l) );
        }

        printf("Case %d:\n",++test);

        read(q);

        while(q--)
        {
            read(i);
            read(j);
            read(k);
            l = dijkstra(n, j, k, i);
            if(l == -1) printf("impossible\n");
            else printf("%d\n",l);
        }
    }

    return 0;
}
