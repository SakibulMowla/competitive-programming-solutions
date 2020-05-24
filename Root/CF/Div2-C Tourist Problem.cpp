#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define SZ 100010

inline ll GCD (ll a, ll b) {
    if (b == 0) return a;
    return GCD(b, a%b);
}

ll a[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    stable_sort(a+1, a+n+1);

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += (ll)(i-1) * a[i] - a[i-1];
        a[i] += a[i-1];
    }

    ans = 2LL * ans + a[n];

    cout << ans / GCD(ans, n) << ' ' << n / GCD(n, ans) << '\n';

    return 0;
}






