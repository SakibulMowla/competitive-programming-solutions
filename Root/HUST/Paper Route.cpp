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

//#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())


typedef long long ll;
const ll inf = 1e10;

#define sz(a) (ll)a.size()
#define SZ 100010

struct data
{
    int to, cost;
    data() {}
    data(ll a,ll b)
    {
        to = a;
        cost = b;
    }
};

vector <data> adj[SZ];
queue <int> Q;
ll campus[SZ];
int dist[SZ];

void BFS()
{
    int i, j, k, u;

    while(!Q.empty()) Q.pop();

    dist[0] = 0;
    Q.push(0);

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        k = sz(adj[u]);
        for(i=0; i<k; i++)
        {
            j = adj[u][i].to;
            if(dist[j] != -1) continue;
            dist[j] = dist[u] + adj[u][i].cost;
            Q.push(j);
        }
    }

    return ;
}

int main()
{
//    freopen("1.txt","r",stdin);
//    freopen("2.txt","w",stdout);
    int n, i, j, k, l;
    ll tot, ans;

    while(scanf("%d",&n) == 1)
    {
        //        memset(dist, -1, sizeof(ll)*(n+2));

        for(i=0; i<=n; i++)
            adj[i].clear(), dist[i] = -1, scanf("%lld",&campus[i]);

        tot = 0LL;

        for(i=0; i<n; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            adj[j].push_back( data(k, l) );
            adj[k].push_back( data(j, l) );
            tot += (ll)(l<<1LL);
        }


//        printf("tot = %lld\n",tot);
        BFS();

        ans = inf;

        for(i=0; i<=n; i++)
        {
//            printf("i = %d dist[i] = %d cam = %lld\n",i,dist[i],campus[i]);
               ans = min(ans, tot-(ll)dist[i]+campus[i]);
//            printf("ans = %lld\n",ans);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
