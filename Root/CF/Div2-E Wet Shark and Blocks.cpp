#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = (1E9)+7;

ll mod2 = mod * mod;

#define SZ 100010

struct matrix {
    ll x[100][100];
};
matrix base, zero;

matrix matmult (matrix &a, matrix &b, int n) {
    matrix ret;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        ret.x[i][j] = 0;
        for (int k = 0; k < n; k++) {
            ret.x[i][j] = ret.x[i][j] + a.x[i][k] * b.x[k][j];
            if (ret.x[i][j] >= mod2) ret.x[i][j] -= mod2;
        }
        ret.x[i][j] %= mod;
    }
    return ret;
}

matrix bigmod(matrix b, ll p, int n) {
    matrix xx = zero;
    int i;
    for (int i = 0; i < n; i++) xx.x[i][i] = 1;
    matrix power = b;
    while(p) {
        if (p & 1) xx = matmult(xx, power, n);
        power = matmult(power, power, n);
        p /= 2;
    }
    return xx;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, b, k, x;
    while (cin >> n >> b >> k >> x) {
        vector <int> cnt(10, 0);
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            cnt[tmp]++;
        }

        base = zero;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < 10; j++) {
                int now = ((i * 10) + j) % x;
                base.x[i][now] += cnt[j];
            }
        }

        cout << bigmod(base, b, x).x[0][k] << endl;
    }

    return 0;
}





