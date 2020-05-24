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
#include <time.h>

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


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

bool vis[SZ][10];
long double dp[SZ][10];

int k;

long double solve (int pos, int n) {
    long double &ret = dp[pos][n];
    if (vis[pos][n]) return ret;
    vis[pos][n] = 1;
    if (pos == 0) return ret = 1.0;

    ret = solve(pos-1, n);
    if (n+1 <= k) ret += solve(pos-1, n+1);
    if (n-1 >= 0) ret += solve(pos-1, n-1);

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    while (scanf("%d %d", &k, &n) == 2) {
        mem(vis, 0);
        long double ans = 0.0;
        for (int i = 0; i <= k; i++) {
            ans += solve(n-1, i);
        }
        ans *= 100.0;
        for (int i = 0; i < n; i++) {
            ans /= (long double)(k+1);
        }
        printf("%.5Lf\n", ans);
    }

    return 0;
}




