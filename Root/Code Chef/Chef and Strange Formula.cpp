#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

ll f[10000000+1];

int main() {
    int n;
    ll m;
    scanf("%d %lld", &n, &m);

    f[0] = 1 % m;
    for (int i = 1; i <= 10000000; i++) {
        f[i] = ((ll)i * f[i-1]) % m;
        if (f[i] == 0) {
            break;
        }
    }

    ll ans = 0;
    ll a, b, x;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);

        a = x;
        b = x + 1;
        if (a&1) b >>= 1LL;
        else a >>= 1LL;
        a %= m;
        b %= m;
        a = (a * b) % m;
        a = (a * (x % m)) % m;

        ans = ans + a;
        if (ans >= m) ans -= m;

        a = (x+1LL >= m ? 0LL : f[x+1]) - f[1];
        if (a < 0) a += m;

        ans = ans + a;
        if (ans >= m) ans -= m;
    }

    printf("%lld\n", ans);

    return 0;
}



