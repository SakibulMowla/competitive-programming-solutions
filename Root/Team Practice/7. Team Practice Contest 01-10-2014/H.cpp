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

int x[] = {0,0,-1,1};//4-way
int y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  510

char arr[SZ][SZ];
bool vis[SZ][SZ];
int cnt[SZ][SZ];

queue <int> Q;

void hit(int nx, int ny, int n, int m) {
    for(int i = 0; i < 4; i++) {
        int u = nx + x[i];
        int v = ny + y[i];

        if(u >= 0 && u < n && v >= 0 && v < m && arr[u][v] == '*') {
            cnt[u][v]++;
            if(cnt[u][v] == 2) arr[u][v] = '.';
        }
    }
}

void BFS(int sx, int sy, int ex, int ey, int n, int m) {
    while(!Q.empty()) Q.pop();

    vis[sx][sy] = 1;
    Q.push(sx);
    Q.push(sy);
    hit(sx, sy, n, m);

    while(!Q.empty()) {
        int nx = Q.front(); Q.pop();
        int ny = Q.front(); Q.pop();

        for(int i = 0; i < 4; i++) {
            int u = nx + x[i];
            int v = ny + y[i];

            if(u >= 0 && u < n && v >= 0 && v < m && vis[u][v] == 0 && arr[u][v] == '.') {
                vis[u][v] = 1;
                Q.push(u);
                Q.push(v);
                hit(u, v, n, m);
            }
        }
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; i++)
            scanf("%s", arr[i]);

        int sx, sy, ex, ey;

        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        --sx, --sy, --ex, --ey;

        mem(vis, 0);
        mem(cnt, 0);
        BFS(sx, sy, ex, ey, n, m);

        if(vis[ex][ey]) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}



















