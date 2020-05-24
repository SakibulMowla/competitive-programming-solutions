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

const ll inf = 1E17;
const ll mod = 1E9;


#define SZ 100010

int arr[SZ];
vector <ll> prime;

void sieve () {
    int lim = sqrt(SZ);
    for (int i = 3; i <= lim; i += 2) {
        if (!arr[i]) {
            for (int j = i * i; j < SZ; j += i + i) {
                arr[j] = 1;
            }
        }
    }
    prime.pb(2);
    for (int i = 3; i < SZ; i += 2) {
        if (!arr[i]) {
            prime.pb(i);
        }
    }
    return;
}

void factorize (vector <ll>& factors, ll n) {
    for (int i = 0; i < sz(prime) && prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            factors.pb(prime[i]);
            while (n % prime[i] == 0) {
                n /= prime[i];
            }
        }
    }
    if (n != 1) {
        factors.pb(n);
    }
    return;
}

bool check (ll n, ll x) {
    return ((n-1LL) % x == 0) || ((n+1LL) % x == 0);
}

ll solve (vector <ll>& v, int n, ll a, ll b, ll x) {
    vector < vector <ll> > dp(3, vector <ll> (n, inf));

    if (v[0] % x == 0) {
        dp[0][0] = 0;
    } else {
        dp[1][0] = a;
        if (check(v[0], x)) {
            dp[0][0] = b;
        }
    }

    for (int i = 0; i <= 2; i++) { // 0 --> hasn't started, 1 --> has started, 2 --> finished
        for (int j = 1; j < n; j++) {
            if (i == 0) {
                if (v[j] % x == 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                } else if (check(v[j], x)) {
                    dp[i][j] = min(dp[i][j], b + dp[i][j-1]);
                }
            } else if (i == 1) {
                dp[i][j] = min(dp[i][j], a + min(dp[0][j-1], dp[1][j-1]));
            } else {
                if (v[j] % x == 0) {
                    dp[i][j] = min(dp[i][j], min(dp[0][j-1], min(dp[1][j-1], dp[2][j-1])));
                } else if (check(v[j], x)) {
                    dp[i][j] = min(dp[i][j], min(dp[0][j-1], min(dp[1][j-1], dp[2][j-1])) + b);
                }
            }
        }
    }

    return min(dp[0][n-1], min(dp[1][n-1], dp[2][n-1]));
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    sieve();

    int n;
    while (cin >> n) {
        ll a, b;
        cin >> a >> b;

        vector <ll> v(n);
        for (auto &x: v) {
            cin >> x;
        }

        vector <ll> factors;

        factorize(factors, v[0]);
        factorize(factors, v[0] - 1);
        factorize(factors, v[0] + 1);
        factorize(factors, v[n-1]);
        factorize(factors, v[n-1] - 1);
        factorize(factors, v[n-1] + 1);

        sort(factors.begin(), factors.end());
        factors.resize(unique(factors.begin(), factors.end()) - factors.begin());

        ll ans = a * (ll)(n - 1);
        for (auto x: factors) {
            ans = min(ans, solve(v, n, a, b, x));
        }

        cout << ans << endl;
    }

    return 0;
}

/*
7 46 23
47 17 90 30 39 6 63

46
*/


