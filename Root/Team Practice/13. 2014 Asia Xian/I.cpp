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


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 10000007LL;

#define SZ  160

struct matrix {
    ll x[16][16];
};

matrix zero, base, eye;
int n;
ll b[16];

matrix matmult (matrix &a, matrix &b) {
    matrix ret = zero;
    for (int i = 0; i <= n; i++)
        for (int k = 0; k <= n; k++)
            for (int j = 0; j <= n; j++) {
                ret.x[i][j] += a.x[i][k] * b.x[k][j];
                if (ret.x[i][j] >= mod * mod)
                    ret.x[i][j] -= mod * mod;
            }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            ret.x[i][j] %= mod;
    return ret;
}

matrix BigMod (int p) {
    if (p == 0) return eye;
    if (p == 1) return base;
    matrix x = BigMod(p/2);
    x = matmult(x, x);
    if (p&1) x = matmult(x, base);
    return x;
}

void pre (int n) {
    eye = zero;
    for (int i = 0; i <= n; i++)
        eye.x[i][i] = 1;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    base = zero;

    base.x[0][0] = 1;
    for (int i = 1; i < 16; i++)
        for (int j = 0; j <= i; j++) {
            if (j == 0) base.x[i][j] = 3;
            else if (j == 1) base.x[i][j] = 10;
            else base.x[i][j] = 1;
        }

    int m;
    while (cin >> n >> m) {
        n++;
        pre(n);

        b[0] = 1LL;
        b[1] = 23LL;
        for (int i = 2; i <= n; i++) {
            cin >> b[i];
        }

        matrix power = BigMod(m);

        ll ans = 0LL;
        for (int i = 0; i <= n; i++)
            ans = (ans + power.x[n][i] * b[i]) % mod;

        cout << ans << '\n';
    }

    return 0;
}







