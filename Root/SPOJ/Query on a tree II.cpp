using namespace std;

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "vector"
#include "iostream"
#define SZ 10100

typedef long long ll;

ll n , P[SZ][15] , dist[SZ] , lvl[SZ];
bool col[SZ];

struct data
{
    ll to,di;
    data(ll a,ll b)
    {
        to = a;
        di = b;
    }
};

vector <data> adj[SZ];

void init()
{
    ll i;
    for(i=0; i<=n; i++)
    {
        adj[i].clear();
        col[i] = 0;
    }
}

void dfs(ll source)
{
    col[source] = 1;

    ll i,j,k;
    k = adj[source].size();

    for(i=0; i<k; i++)
    {
        j = adj[source][i].to;
        if(col[j] == 0)
        {
            lvl[j] = lvl[source] + 1;
            P[j][0] = source;
            dist[j] = dist[source] + adj[source][i].di;
            dfs(j);
        }
    }
}

void build()
{
    ll i,j,h,lev;

    for(h=1; (1LL<<h) <= n; h++);
    --h;

    for(i=0; i<=n; i++)
        for(j=0; j<=h; j++)
            P[i][j] = -1;

    lvl[1] = dist[1] = 0;
    dfs(1);

    for(lev=1; lev<=h; lev++)
        for(i=1; i<=n; i++)
            if(P[i][lev-1] != -1)
                P[i][lev] = P[ P[i][lev-1] ][lev-1];
}

ll DIST_query(ll p,ll q)
{
    if(lvl[p] < lvl[q]) swap(p,q);

    ll i,h;

    for(h=1; (1LL<<h) <= lvl[p] ; h++);
    --h;

    for(i=h; i>=0; i--)
    {
        if(lvl[p] - (1LL<<i) >= lvl[q])
            p = P[p][i];
    }

    if(p == q) return p;

    for(i=h; i>=0; i--)
    {
        if(P[p][i] != -1 && P[q][i] != -1 && P[p][i] != P[q][i])
        {
            p = P[p][i];
            q = P[q][i];
        }
    }

    return P[p][0];
}

ll KTH_query(ll p,ll q,ll k)
{
    ll r = DIST_query(p,q) , path , i, h;

    if(lvl[p] - lvl[r] + 1 >= k)
    {
        path = 1;
        for(h=1; (1LL<<h)<=lvl[p]; h++);
        --h;

        for(i=h; i>=0; i--)
        {
            if(path + pow(2,i) <= k)
                p = P[p][i] , path += pow(2,i);
        }

        return p;
    }

    else
    {
        k = k - (lvl[p] - lvl[r] + 1);
        k =(lvl[q] - lvl[r] + 1) - k;

        path = 1;
        for(h=1; (1LL<<h)<=lvl[q]; h++);
        --h;

        for(i=h; i>=0; i--)
        {
            if(path + pow(2,i) <= k)
                q = P[q][i] , path += pow(2,i);
        }

        return q;
    }
}

int main()
{
    ll t, i, a, b, c;
    char arr[10];
    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        init();

        for(i=0; i<n-1; i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            adj[a].push_back( data(b,c) );
            adj[b].push_back( data(a,c) );
        }

        build();

        while(scanf("%s",arr) == 1)
        {
            if(arr[0] == 'K')
            {
                scanf("%lld %lld %lld",&a,&b,&c);
                printf("%lld\n",KTH_query(a,b,c));
            }

            else if(arr[1] == 'I')
            {
                scanf("%lld %lld",&a,&b);
                c = DIST_query(a,b);
                a = dist[a] + dist[b] - 2 * dist[c];
                printf("%lld\n",a);
            }

            else break;
        }

        printf("\n");
    }

    return 0;
}
