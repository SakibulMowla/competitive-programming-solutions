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

#define SZ  20

double dp[(1<<20)+10];
int col[(1<<20)+10];
int cur;
pii point[SZ+2];

double dist(int a, int b) {
    double d = (point[a].X-point[b].X)*(point[a].X-point[b].X) + (point[a].Y-point[b].Y)*(point[a].Y-point[b].Y);
    return sqrt(d);
}

int N;

double solve(int mask) {
    if(!mask) return 0.0;

    if(col[mask] == cur) return dp[mask];
    col[mask] = cur;

    double &ret = dp[mask];
    ret = 1e17;

    for(int i = 0; i < N; i++) if(mask & (1<<i)) {
        for(int j = i + 1; j < N; j++) if(mask & (1<<j)) {
            ret = min(ret, dist(0, i+1) + dist(i+1, j+1) + solve(mask & ~((1<<i)|(1<<j)) ));
            ret = min(ret, dist(0, j+1) + dist(j+1, i+1) + solve(mask & ~((1<<i)|(1<<j)) ));
        }
        break;
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t, test = 0;

    scanf("%d", &t);
    while(t--) {
        int j, k;
        scanf("%d %d", &j, &k);
        point[0] = MP(j, k);

        scanf("%d", &N);
        N <<= 1;

        for(int i = 0; i < N; i++) {
            scanf("%d %d", &j, &k);
            point[i+1] = MP(j, k);
        }

        cur++;
        printf("Case #%d: %.2lf\n", ++test, solve((1<<N)-1));
    }


    return 0;
}













