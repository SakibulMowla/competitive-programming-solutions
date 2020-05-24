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

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


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
const int inf = 1e9;
const ll mod = 1LL;

#define SZ 15

struct data{
    int to, cost;
    data(){}
    data(int a, int b){
        to = a, cost = b;
    }
    bool operator < (const data &x) const{
        return cost > x.cost;
    }
};

vector <data> adj[SZ];
priority_queue <data> pq;
int dist[SZ];
int par[SZ];

void dijkstra(int strt){
    while(!pq.empty()) pq.pop();

    int i, j, k, l, v, c;
    data u;

    REP1(i, 1, 10) dist[i] = inf, par[i] = -1;

    pq.push(data(strt, 0));
    dist[strt] = 0;
    par[strt] = -1;

    while(!pq.empty()){
        u = pq.top(); pq.pop();

        j = u.to;
        k = u.cost;
        l = sz(adj[j]);

        REP(i, l){
            v = adj[j][i].to;
            c = adj[j][i].cost;

            if(dist[v] > dist[j] + c){
                dist[v] = dist[j] + c;
                par[v] = j;
                pq.push(data(v, dist[v]));
            }
        }
    }
}

void path(int u){
    if(par[u] == -1){
        printf(" %d",u);
        return;
    }

    path(par[u]);
    printf(" %d",u);
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test=0, n, i, j, jj, k, l, strt, end;

    while(scanf("%d",&n) == 1 && n){
        REP1(i, 1, n) clr(adj[i]);

        REP1(i, 1, n){
            scanf("%d",&l);
            REP(j, l){
                scanf("%d %d",&jj,&k);
                adj[i].pb(data(jj, k));
            }
        }

        scanf("%d %d",&strt,&end);

        printf("Case %d: Path =",++test);
        dijkstra(strt);
        path(end);
        printf("; %d second delay\n",dist[end]);
    }


    return 0;
}













