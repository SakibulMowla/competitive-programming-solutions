#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const int mod = 10000;

#define SZ 100010

struct matrix {
    int xx[3][3];
};

matrix zero;

matrix multiply (matrix &a, matrix & b, int n) { /// 1st Matrix, 2ns Matrix, Dimension
    matrix ret = zero;
    int sqrmod = mod * mod;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                ret.xx[i][j] += a.xx[i][k] * b.xx[k][j];
                if (ret.xx[i][j] >= sqrmod) ret.xx[i][j] -= sqrmod;
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ret.xx[i][j] %= mod;

    return ret;
}

matrix BigMod (matrix base, int p, int n) {
    matrix ret = zero;
    for (int i = 1; i <= n; i++)
        ret.xx[i][i] = 1;
    while (p) {
        if (p&1) ret = multiply(ret, base, n);
        base = multiply(base, base, n);
        p >>= 1;
    }
    return ret;
}

 inline void formatted_print (int ans, int place) {
    if (place == 1) ans %= 10;
    else if (place == 2) ans %= 100;
    else if (place == 3) ans %= 1000;
    else ans %= 10000;
    cout << ans << '\n';
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    matrix keep, base;
    keep.xx[1][1] = 1; keep.xx[1][2] = 1;
    keep.xx[2][1] = 1; keep.xx[2][2] = 0;

    int a, b, n, m;
    int ans;
    int t;

    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> a >> b >> n >> m;

        if (n == 0) formatted_print(a, m);
        else if (n == 1) formatted_print(b, m);
        else {
            base = BigMod(keep, n-1, 2);
            ans = ((b * base.xx[1][1]) % mod + (a * base.xx[1][2]) % mod) % mod;
            formatted_print(ans, m);
        }
    }

    return 0;
}






