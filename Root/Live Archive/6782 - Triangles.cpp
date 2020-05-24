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
#define pb push_back

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
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

#define SZ  1010

struct data {
    int l[3];
    double g;
};

bool comp(data p, data q) {
    return p.g < q.g;
}

data arr[SZ];
int dp[SZ][3];
int col[SZ][3];
int now, n;

int solve(int pos, int side) {
    int &ret = dp[pos][side];
    if(col[pos][side] == now) return ret;

    col[pos][side] = now;
    ret = 0;

    for (int i = pos+1; i < n; i++) if (arr[i].g != arr[pos].g)
        for (int j = 0; j < 3; j++) if (arr[pos].l[side] == arr[i].l[j])
            for (int k = 0; k < 3; k++) if (k != j)
                ret = max(ret, 1 + solve(i, k));

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    while(scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %lf", &arr[i].l[0], &arr[i].l[1], &arr[i].l[2], &arr[i].g);
        }

        sort(arr, arr+n, comp);
        now++;

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                ans = max(ans, solve(i, j));

        printf("%d\n", ans + 1);
    }


    return 0;
}













