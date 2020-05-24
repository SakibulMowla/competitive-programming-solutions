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
#include <deque>
#include <assert.h>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  1010

vector <int> adj[SZ];
set <pii> bridge;
int low[SZ], tym[SZ], timer;

void art_bridge(int u, int par)
{
    low[u] = tym[u] = timer++;
    for(int i = 0; i < sz(adj[u]); i++)
    {
        int v = adj[u][i];
        if(v == par) continue;
        if(tym[v] == 0)
        {
            art_bridge(v, u);
            low[u] = min(low[u], low[v]);
            if(tym[u] < low[v])
            {
                bridge.insert( MP( min(u, v), max(u, v) ) );
            }
        }
        else if(tym[u] > tym[v])
            low[u] = min(low[u], tym[v]);
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m;

    while(scanf("%d %d", &n, &m) == 2 && (n+m))
    {
        mem(low, 0);
        mem(tym, 0);
        bridge.clear();
        timer = 1;
        for(int i = 0; i < n; i++)
            adj[i].clear();

        for(int i = 0; i < m; i++)
        {
            int j, k;
            scanf("%d %d", &j, &k);
            adj[j].pb(k);
            adj[k].pb(j);
        }

        for(int i = 0; i < n; i++)
            if(tym[i] == 0)
                art_bridge(i, i);

        printf("%d", sz(bridge));
        for(set<pii>::iterator it = bridge.begin(); it != bridge.end(); it++)
            printf(" %d %d", it->X, it->Y);
        puts("");
    }


    return 0;
}












