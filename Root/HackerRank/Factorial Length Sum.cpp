#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  1000010

int arr[SZ];
vector <int> prime;

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

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    sieve();

    int n;
    cin >> n;

    vector <int> a(n), val(n, 0);
    int lim = (1 << n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < sz(prime) && prime[j] <= a[i]; j++) {
            int tmp = a[i];
            while (tmp >= prime[j]) {
                val[i] += (tmp / prime[j]);
                tmp /= prime[j];
            }
        }
    }

    ll ans = 0;
    for (int mask = 0; mask < lim; mask++) {
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                tmp += val[i];
            }
        }
        if (tmp % 2 == 0) {
            ans += tmp;
        }
    }

    cout << ans << endl;

    return 0;
}



