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

int a[SZ];
int dp[SZ][SZ*SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int col = 0;

    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        int sum = 0;
        for (int i = 1; i <= n + m; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            a[i] += 50;
        }

        dp[0][0] = ++col;
        for (int i = 1; i <= n + m; i++) {
            for (int j = min(n, i); j >= 1; j--) {
                for (int k = 0; k <= 10000; k++) {
                    if (dp[j-1][k] == col) {
                        dp[j][k+a[i]] = col;
                    }
                }
            }
        }

        int mn = 1E9;
        int mx = -1E9;
        for (int i = 0; i <= 10000; i++) {
            if (dp[n][i] == col) {
                int tmp = i - 50 * n;
                mx = max(mx, tmp * (sum - tmp));
                mn = min(mn, tmp * (sum - tmp));
            }
        }

        printf("%d %d\n", mx, mn);
    }

    return 0;
}





