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

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

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
const int inf = 1;
const ll mod = 1LL;

#define SZ  1000+10

struct Edge{
    int from, to, len, pre;
};

int top;
Edge edge[2*SZ];
int adj[SZ];

void add_edge(int from, int to) {
    edge[top].from = from;
    edge[top].to = to;
    edge[top].pre = adj[from]; /// previous adjacency of node from
    adj[from] = top++;
}

///FOR BCC
int timer;
int tyme[SZ]; /// discovery time
int low[SZ]; /// low time

void BCC(int u, int par) {
    tyme[u] = low[u] = ++timer;

    for(int i = adj[u]; i != -1; i = edge[i].pre) {
        int v = edge[i].to;
        if(v == par) continue;

        if(tyme[v] == 0) {
            BCC(v, u);
            low[u] = min(low[u], low[v]);
        } else if(tyme[u] > tyme[v]) {
            low[u] = min(low[u], tyme[v]);
        }
    }

    return;
}

void Tarjan_BCC(int n) {
    for(int i = 1; i <= n; i++)
        if(tyme[i] == 0)
            BCC(i, i);
    return;
}

int degree[SZ];

int solve(int n) {
    for(int node = 1; node <= n; node++) {
        for(int i = adj[node]; i != -1; i = edge[i].pre) {
            int to = edge[i].to;
            if(low[node] != low[to]) {
                degree[low[node]]++;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(degree[i] == 1)
            ans++;

    return ans/2+(ans&1);
}

void init(int n) {
    top = 0;
    timer = 0;
    for(int i = 0; i <= n; i++) {
        adj[i] = -1;
        tyme[i] = 0;
        low[i] = 0;
        degree[i] = 0;
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m;

    while(scanf("%d %d", &n, &m) == 2) {
        init(n);

        for(int i = 0; i < m; i++) {
            int j, k;
            scanf("%d %d", &j, &k);
            add_edge(j, k);
            add_edge(k, j);
        }

        Tarjan_BCC(n);
        printf("%d\n", solve(n));
    }


    return 0;
}


/*
5 6
1 2
1 3
2 3
3 4
3 5
4 5
ans = 0
*/



