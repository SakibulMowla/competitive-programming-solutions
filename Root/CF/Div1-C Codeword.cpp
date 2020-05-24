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
const ll mod = 1E9+7;


#define SZ 100010

ll BigMod (ll B, ll P, ll M) {
    ll R = 1 % M;
    while (P > 0) {
        if(P % 2 == 1) {
            R = (R * B) % M;
        }
        P /= 2;
        B = (B * B) % M;
    }
    return R;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    vector <ll> f(200001), inv(200001);

    f[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        f[i] = ((ll)i * f[i-1]) % mod;
    }

    for (int i = 0; i <= 200000; i++) {
        inv[i] = BigMod(f[i], mod - 2, mod);
    }

    vector <ll> b26p(100001), b25p(100001);

    b26p[0] = 1;
    b25p[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        b26p[i] = (26 * b26p[i-1]) % mod;
        b25p[i] = (25 * b25p[i-1]) % mod;
    }

    int q, len;
    char s[100000];

    scanf("%d %s", &q, s);
    len = strlen(s);

    for (int cs = 0; cs < q; cs++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            scanf(" %s", s);
            len = strlen(s);
        } else {
            int n;
            scanf("%d", &n);

            if (n < len) {
                printf("0\n");
            } else if (n == len) {
                printf("1\n");
            } else {
                int lft = n - len;
                ll ans = 0;

                for (int i = 0; i <= lft; i++) {
                    ll tmp = f[n - i - 1];
                    tmp = (tmp * inv[lft - i]) % mod;
                    tmp = (tmp * inv[len - 1]) % mod;
                    tmp = (tmp * b25p[lft - i]) % mod;

                    ans = ans + (tmp * b26p[i]) % mod;

                    if (ans >= mod) {
                        ans -= mod;
                    }
                }

                printf("%I64d\n", ans);
            }
        }
    }

    return 0;
}





