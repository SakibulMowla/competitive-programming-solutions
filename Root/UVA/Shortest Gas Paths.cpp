using namespace std;

#include "stdio.h"
#include "vector"
#include "queue"
#include "iostream"

#define MAX 265
typedef long long ll;

struct data
{
    ll to, cost, typ;
    data() {}
    data(ll a,ll b,ll c)
    {
        to = a, cost = b, typ = c;
    }
};

struct data1
{
    ll to, cost, stamina, typ;
    bool operator < (const data1 & x) const
    {
        return cost > x.cost;
    }
    data1() {}
    data1(ll a,ll b,ll c,ll d)
    {
        to = a, cost = b, stamina = c, typ = d;
    }
};

const ll inf = 1e18;
vector <data> adj[MAX];
priority_queue <data1> Q;
ll dist[MAX], arr[MAX], n;

ll BFS(ll s,ll e)
{
    ll i, j, k, frm, to, cost, cost1, typ, typ1, sta, sta1;
    data1 u,v;

    for(i=0; i<=n; i++)
        dist[i] = inf;
    while(!Q.empty()) Q.pop();

    dist[s] = 0;
    Q.push( data1(s, 0, 100, arr[s]) );

    while( !Q.empty() )
    {
        u = Q.top();
        Q.pop();

        frm = u.to;
        cost = u.cost;
        typ = u.typ;
        sta = u.stamina;
        k = adj[frm].size();

        for(i=0; i<k; i++)
        {
            to = adj[frm][i].to;
            cost1 = adj[frm][i].cost;
            typ1 = adj[frm][i].typ;

            if(sta - cost1 >= 0 && dist[frm] + cost1 < dist[to])
            {
                if(arr[to] == 1) sta1 = 100;
                else sta1 = sta - cost1;
                dist[to] = dist[frm] + cost1;
                cost1 = cost + cost1;
                Q.push( data1(to, cost1, sta1, arr[to]) );
            }

        }
    }

    return dist[e];
}

int main()
{
//    freopen("1.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t, test, i, r, q, a, b, c;
    char ch;

    while(scanf("%lld", &test) == 1)
    {
        t = 0;
        while(test--)
        {
            scanf("%lld %lld %lld", &n, &r, &q);

            for(i=1; i<=n; i++)
            {
                scanf(" %c", &ch);
                if(ch == 'G') arr[i] = 1;
                else arr[i] = 0;
                adj[i].clear();
            }

            for(i=0; i<r; i++)
            {
                scanf("%lld %lld %lld", &a, &b, &c);

                adj[a].push_back( data(b, c, arr[b]) );
                adj[b].push_back( data(a, c, arr[a]) );
            }

            printf("CASE %lld\n", ++t);

            while(q--)
            {
                scanf("%lld %lld", &a, &b);
                if(a < 1 || a > n || b < 1 || b > n)
                {
                    printf("NO GAS PATH\n");
                    continue;
                }
                c = BFS(a, b);
                if(c >= inf) printf("NO GAS PATH\n");
                else printf("%lld\n",c);
            }
        }
    }

    return 0;
}
