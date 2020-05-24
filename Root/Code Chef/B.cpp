#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


#define X first
#define Y second

typedef pair<ll , ll> pll;

#define SZ  110

using pll = pair <ll, ll>;

ll nCr[SZ][SZ];

void preCalc(ll m) {
    nCr[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0) nCr[i][j] = 1;
            else nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
            if (nCr[i][j] >= m) nCr[i][j] -= m;
        }
    }
    return;
}


ll C (ll n, ll r, ll p) {
    return nCr[n][r];
}

pll solve (ll n, ll k, ll m) {
    ll p = (n + k - 1) / k;
    ll left = n - p;
    ll ans = 0;
    for (int i = 0; left >= 0; i++) {
        ll tmp = (C(p, i, m) * C(left + p - 1, p - 1, m)) % m;
        if (i & 1) ans -= tmp;
        else ans += tmp;
        if (ans >= m) ans -= m;
        if (ans < 0) ans += m;
        left -= k;
    }
    return {p, ans};
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll n, k, m;
        cin >> n >> k >> m;

        preCalc(m);
        pll ans = solve(n, k, m);

        cout << ans.X << ' ' << ans.Y << endl;
    }


    return 0;
}


