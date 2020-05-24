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

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 22

vector <int> adj[SZ];
int dist[SZ];

queue <int> Q;

int BFS(int strt, int end){
    while(!Q.empty()) Q.pop();

    int i, u, v, k;

    REP(i, 21) dist[i] = -1;

    dist[strt] = 0;
    Q.push(strt);

    while(!Q.empty()){
        u = Q.front(); Q.pop();
        k = sz(adj[u]);

        REP(i, k){
            v = adj[u][i];
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }

    return dist[end];
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test=0, t, i, j, k, l;

    while(scanf("%d",&l) == 1){
        REP(i, 21) clr(adj[i]);

        REP(i, l){
            scanf("%d",&j);
            adj[1].pb(j);
            adj[j].pb(1);
        }

        REP1(i, 2, 19){
            scanf("%d",&l);
            REP(j, l){
                scanf("%d",&k);
                adj[i].pb(k);
                adj[k].pb(i);
            }
        }

        printf("Test Set #%d\n",++test);

        scanf("%d",&l);
        while(l--){
            scanf("%d %d",&i,&j);
            printf("%2d to %2d: %d\n",i,j,BFS(i, j));
        }

        puts("");
    }



    return 0;
}
















