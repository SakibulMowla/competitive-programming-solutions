#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

#define SZ 6010

typedef long long ll;

const ll inf = 1e9;

struct data
{
    int to, gas, cost;
    bool operator < (const data &x) const
    {
        return cost > x.cost;
    }
    data() {}
    data(int a, int b, int c)
    {
        to = a;
        gas = b;
        cost = c;
    }
};


vector <data> adj[SZ];
priority_queue <data> pq;
int dist[SZ][SZ];
bool stat[SZ];

int dijkstra(int n, int start, int end, int cap)
{
    while(!pq.empty()) pq.pop();

    int i, j, k, w;
    data u;

    for(i=0; i<=n; i++)
        for(j=0; j<=cap; j++)
            dist[i][j] = inf;

    dist[start][0] = 0;
    pq.push( data(start, cap, 0) );

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        if(u.to == end)
            return u.cost;

        if(stat[u.to] == 1 && u.cost+cap-u.gas < dist[u.to][cap])
        {
            dist[u.to][cap] = u.cost+cap-u.gas;
            pq.push( data(u.to, cap, u.cost) );
        }

        k = sz(adj[u.to]);

        for(i=0; i<k; i++)
        {
            j = adj[u.to][i].to;
            w = adj[u.to][i].cost;
            if(u.gas < w) continue;

            if(dist[j][u.gas-w] > u.cost+w)
            {
                dist[j][u.gas-w] = u.cost+w;
                pq.push( data(j, u.gas-w, u.cost+w) );
            }
        }
    }

    return -1;
}


map <string , int> M;
map <string , int>::iterator it;

//%I64d
int main()
{

    int n, m, cap, start, end, cnt, i, j;
    string st, ed;

    while(scanf("%d %d %d",&n,&m,&cap) == 3)
    {
        if(n == 0 && m == 0 && cap == 0)
            break;

        cap *= 10;

        M.clear();
        for(i=0; i<=3000; i++)
        {
            adj[i].clear();
            stat[i] = 0;
        }

        cin >> st >> ed;

        cnt = 1;

        start = M[st] = cnt++;
        if(M.find(ed) == M.end())
            end = M[ed] = cnt++;
        else
            end = M[ed];

        for(i=0; i<n; i++)
        {
            cin >> st >> ed;
            scanf("%d",&j);

            if(M.find(st) == M.end())
                M[st] = cnt++;
            if(M.find(ed) == M.end())
                M[ed] = cnt++;

            adj[ M[st] ].push_back( data( M[ed], 0, j) );
            adj[ M[ed] ].push_back( data( M[st], 0, j) );
        }

        for(i=0; i<m; i++)
        {
            cin >> st;
            if(M.find(st) != M.end())
                stat[ M[st] ] = 1;
        }

        printf("%d\n",dijkstra(cnt, start, end, cap));
    }


    return 0;
}












