using namespace std;
#include "stdio.h"
#include "vector"
#include "iostream"
#include "algorithm"
#define SZ 50500

typedef long long ll;
const ll inf = (1LL<<28);

ll n , P[SZ][20] , dist[SZ][20] , L[SZ] , par[SZ] , col[SZ] , rank[SZ];
struct data
{
    ll x,y,d;
    data(ll a,ll b,ll c)
    {
        x = a , y = b , d = c;
    }
};
vector <data> input;

struct data1
{
    ll to,cost;
    data1(ll a,ll b)
    {
        to = a , cost = b;
    }
};
vector <data1> edge[SZ];

void init()
{
    input.clear();
    ll i;
    for(i=0; i<=n; i++)
    {
        edge[i].clear();
        par[i] = i;
        rank[i] = 0;
        col[i] = 0;
    }
}

ll find(ll r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void Union(ll a,ll b)
{
    if(rank[a] > rank[b]) par[b] = a;
    else par[a] = b;
    if(rank[a] == rank[b]) rank[b]++;
}

bool comp(data p,data q)
{
    return p.d < q.d;
}

void MST()
{
    sort(input.begin(),input.end(),comp);
    ll i,j,k,k1,p=0;
    k = input.size();
    for(i=0; i<k && p < n-1; i++)
    {
        j = find(input[i].x);
        k1 = find(input[i].y);
        if(j != k1)
        {
            p++;
            Union(j,k1);
            edge[ input[i].x ].push_back( data1(input[i].y , input[i].d) );
            edge[ input[i].y ].push_back( data1(input[i].x , input[i].d) );
        }
    }
}

void DFS(int source)
{
    col[source] = 1;
    ll i,j,k;
    k = edge[source].size();
    for(i=0; i<k; i++)
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
    ll i,j,h,lev;

    for(h=1; (1LL<<h)<=n; h++); --h;

    for(i=0; i<=n; i++)
        for(j=0; j<=h; j++)
            P[i][j] = -1 , dist[i][j] = 0;

    L[1] = 0;
    DFS(1);

    for(lev=1; lev<=h; lev++)
        for(i=1; i<=n; i++)
            if(P[i][lev-1] != -1)
            {
                dist[i][lev] = max(dist[i][lev-1] , dist[ P[i][lev-1] ][lev-1]);
                P[i][lev] = P[ P[i][lev-1] ][lev-1];
            }
}

ll query(ll p ,ll q)
{
    if(L[p] < L[q]) swap(p,q);
    ll i,h,maxim = -inf;
    for(h=1; (1LL<<h)<=L[p]; h++); --h;
    for(i=h; i>=0; i--)
    {
        if(L[p] - (1LL<<i) >= L[q])
        {
            maxim = max(maxim , dist[p][i]);
            p = P[p][i];
        }
    }
    if(p == q) return maxim;
    for(i=h; i>=0; i--)
    {
        if(P[p][i] != -1 && P[q][i] != -1 && P[p][i] != P[q][i])
        {
            maxim = max(maxim , max( dist[p][i] , dist[q][i] ));
            p = P[p][i];
            q = P[q][i];
        }
    }
    return max(maxim , max( dist[p][0] , dist[q][0] ));
}

int main()
{
//    freopen("1.txt","r",stdin);
    ll i,j,k,c,m,blank=0;
    while(scanf("%lld %lld",&n,&m) == 2)
    {
        init();
        for(i=0; i<m; i++)
        {
            scanf("%lld %lld %lld",&j,&k,&c);
            input.push_back( data(j,k,c) );
        }
        MST();
        process();
        if(blank) printf("\n");
        blank = 1;
        scanf("%lld",&c);
        while(c--)
        {
            scanf("%lld %lld",&j,&k);
            printf("%lld\n",query(j,k));
        }
    }

    return 0;
}
