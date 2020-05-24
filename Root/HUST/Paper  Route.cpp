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
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;

ll campus[SZ];

struct data
{
    ll to, cost;

    data(){}

    data(ll a, ll b)
    {
        to = a;
        cost = b;
    }
};

vector <data> adj[SZ];
queue <ll> Q;
ll dist[SZ];

void bfs()
{
    while(!Q.empty()) Q.pop();

    ll i, j, k, v;

    Q.push(0);
    dist[0] = 0;

    while(!Q.empty())
    {
        i = Q.front();
        Q.pop();

        k = sz(adj[i]);

        for(j=0; j<k; j++)
        {
            v = adj[i][j].to;
            if(dist[v] != -1) continue;

            dist[v] = dist[i] + adj[i][j].cost;
        }
    }

    return ;
}

//%lld
int main()
{
    ll n, m, i, j, k, l, tot, ans;

    while(scanf("%lld",&n) == 1)
    {
        for(i=0; i<=n; i++)
            scanf("%lld",&campus[i]);

        for(i=0; i<=n; i++)
            adj[i].clear(), dist[i] = -1;
//        memset(dist, -1, sizeof(ll)*(n+2));
        tot = 0LL;

        for(i=0; i<n; i++)
        {
            scanf("%lld %lld %lld",&j,&k,&l);
            adj[j].push_back( data(k,l) );
            adj[k].push_back( data(j,l) );
            tot += (l*2);
        }

//        tot *= 2;
        ans = 1e14;

        bfs();

//        printf("tot = %lld\n",tot);

        for(i=0; i<=n; i++)
        {
//            printf("dist %lld %lld\n",i,dist[i]);
            ans = min(ans, tot-dist[i]+campus[i]);
        }

        printf("%lld\n",ans);
    }



    return 0;
}





