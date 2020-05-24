#include "bits/stdc++.h"

using namespace std;

#define SZ 10010

typedef long long ll;

struct data
{
    ll x, y, d;
};

bool comp(data p, data q)
{
    return p.d < q.d;
}

struct data1
{
    ll x, y;
};

vector <data1> point;
vector <data> graph;
ll par[SZ];

ll find(ll r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}


ll MST(ll n,ll m)
{
    sort(graph.begin(),graph.end(),comp);

    ll i, j, k, x, y, edge = 0, maxim = 0;
    double dist;

    k = graph.size();

    for(i=0;i<k && edge<n-m;i++)
    {
        x = find(graph[i].x);
        y = find(graph[i].y);

        if(x == y) continue;

        edge++;
        par[x] = y;
//        printf("d = %lld\n",graph[i].d);
        if(graph[i].d > maxim)
            maxim = graph[i].d;
    }

    dist = sqrt((double)maxim);
    dist = ceil(dist);

    return (ll) dist;
}

int main()
{
    ll i, j, t, n, m, d, p, q;
    data1 u;
    data v;

    scanf("%lld",&t);

    while(t--)
    {
        n = 0;
        point.clear();
        graph.clear();

        scanf("%lld",&m);

        scanf("%lld",&u.x);

        while(u.x != -1)
        {
            scanf("%lld",&u.y);
            point.push_back(u);
            n++;

            scanf("%lld",&u.x);
        }

        for(i=0;i<=n;i++)
            par[i] = i;

        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
            {
                p = point[i].x-point[j].x;
                q = point[i].y-point[j].y;
                d = p*p + q*q;

                v.x = i;
                v.y = j;
                v.d = d;

                graph.push_back(v);
            }

        printf("%lld\n",MST(n, m));
    }


    return 0;
}
