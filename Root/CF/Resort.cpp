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
#define X first
#define Y second

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

bool col[SZ];
int mark[SZ];
int path[SZ];
vector <int> adj[SZ];

pii dp[SZ];
int start, best, n;

pii dfs(int u,int dist)
{
//    printf("u = %d\n",u);
    col[u] = 1;
    if(mark[u] == 1)
    {
        return dp[u] = MP(1, 1);
    }

    int i, j, k;

    k = sz(adj[u]);

    if(k != 1)
        return dp[u] = MP(0, 0);

    pii tmp = MP(0, 0);

    if(col[adj[u][0]] == 0)
        tmp = dfs(adj[u][0], dist+1);

    else
        tmp = dp[adj[u][0]];

    if(tmp.X == 1)
    {
        tmp.X = 1;
        tmp.Y = tmp.Y + 1;
    }

    return dp[u] = tmp;
}

bool f;

void print(int u,int d)
{
    if(f)
        return;

    if(printf("%d ",u));
    if(d == 1)
    {
        f = 1;
        return;
    }

    print(adj[u][0], d-1);
}

//%I64d
int main()
{
    scanf("%d",&n);

    int i, j, k;

    for(i=1;i<=n;i++)
        scanf("%d",&mark[i]);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&j);
        if(j == 0) continue;
        adj[j].push_back(i);
    }

    best = 0;
    pii tmp;

    for(i=1;i<=n;i++)
    {
        if(col[i] == 0)
        {
//            printf("masin\n");
            tmp = dfs(i, 0);
            if(tmp.X == 1 && tmp.Y > best)
            {
                best = tmp.Y;
                start = i;
            }
        }
    }

    f = 0;
   printf("%d\n",best);

   print(start, best);

    return 0;
}

