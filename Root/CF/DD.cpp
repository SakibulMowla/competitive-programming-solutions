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
const ll mod = 1E9 + 7;

#define SZ 200010

ll BigMod (ll B, ll P, ll M) {
    ll R = 1 % M;
    while(P > 0) {
        if(P % 2 == 1) {
            R = (R * B) % M;
        }
        P /= 2;
        B = (B * B) % M;
    }
    return R;
}

ll f[SZ];

ll nCr (int n, int r) {
    ll ans = f[n];
    ans = (ans * BigMod(f[r], mod - 2, mod)) % mod;
    ans = (ans * BigMod(f[n - r], mod - 2, mod)) % mod;
    return ans;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    f[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        f[i] = (i * f[i - 1]) % mod;
    }

    string s;
    cin >> s;
    int n = sz(s);
    s = '$' + s;
    vector <int> sum(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + (s[i] == '(');
    }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '(') {
            int leftBracket = sum[i];
            int rightBracket = (n - i) - (sum[n] - sum[i]);
            if (leftBracket >= 1 && rightBracket >= 1) ans = ans + nCr(leftBracket + rightBracket - 1, leftBracket);
            if (ans >= mod) ans -= mod;
        }
    }

    cout << ans << endl;

    return 0;
}





