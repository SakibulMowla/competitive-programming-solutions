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

#define SZ  1010

struct Edge{
    int from, to, len, pre;
};

Edge edge[50000*2 + 10];
int n, m;
int top;
int adj[SZ];
int path[SZ];
int dist[SZ];
int vis[SZ];
bool first;

void add_edge(int from, int to, int len) {
    edge[top].from = from;
    edge[top].to = to;
    edge[top].len = len;
    edge[top].pre = adj[from];
    adj[from] = top++;
}

void init(int n) {
    top = 0;
    mem(path, -1);
    mem(adj, -1);
}

struct data {
    int node, cost;
    data() {}
    data(int _node, int _cost) {
        node = _node, cost = _cost;
    }
    bool operator < (const data &x) const {
        return cost > x.cost;
    }
};

priority_queue <data> pq;

int spfa(int start) {
    while(!pq.empty()) pq.pop();

    for(int i = 1; i <= n; i++) dist[i] = inf;

    pq.push(data(1, 0));
    dist[1] = 0;

//    printf("ok\n");

    while(!pq.empty()){
        int x = pq.top().node;
        int y = pq.top().cost;
        pq.pop();

//        printf("x = %d y = %d\n", x, y);

        for(int i = adj[x]; i != -1; i = edge[i].pre) {
            int v = edge[i].to;
            int w = edge[i].len;
//            printf("v = %d w = %d\n", v, w);
            if(dist[v] > dist[x] + w) {
                dist[v] = dist[x] + w;
                if(first) path[v] = i;
                pq.push(data(v, dist[v]));
            }
        }
    }

//    printf("end\n");

    return dist[n];
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n , &m);

        init(n); ///initializing thr graph

        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }

        first = true;
        int ans = spfa(1);
        first = false;

        int node = n;
        while(path[node] != -1) {
            int e = path[node];
            int tmp = edge[e].len;
            edge[e].len = edge[e ^ 1].len = inf;
            ans = max(ans, spfa(1));
            edge[e].len = edge[e ^ 1].len = tmp;
            node = edge[e].from;
        }

        printf("%d\n", ans == inf ? -1 : ans);
    }

    return 0;
}













