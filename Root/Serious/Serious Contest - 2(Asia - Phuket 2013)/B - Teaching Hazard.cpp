#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

bool arr[SZ];
vector <int> prime;

void sieve () {
    int k = sqrt(SZ);
    for (int i = 3; i <= k; i += 2) {
        for (ll j = (ll)i * (ll)i; j < SZ; j += i + i) {
            arr[j] = 1;
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

ll solve (int base, int n) {
    ll ans = 1E18;
    for (int i = 0; (ll)prime[i] * (ll)prime[i] <= base; i++) {
        if (base % prime[i] == 0) {
            while (base % prime[i] == 0) {
                base /= prime[i];
            }
            int tmpn = n;
            ll cnt = 0;
            while (tmpn / prime[i] > 0) {
                cnt += tmpn / prime[i];
                tmpn /= prime[i];
            }
            ans = min(ans, cnt);
        }
    }
    if (base != 1) {
        int tmpn = n;
        ll cnt = 0;
        while (tmpn / base > 0) {
            cnt += tmpn / base;
            tmpn /= base;
        }
        ans = min(ans, cnt);
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    sieve();

    int n, x;
    map <ll, ll> mp;

    while (cin >> n >> x && (n + x)) {
        clr(mp);

        for (int base = 2; base <= n + 1; base++) {
            ll tmp = solve(base, n);
            if (tmp >= x) {
                mp[tmp]++;
            }
            cout << ">> base = " << base << " zero = " << tmp << endl;
        }

        ll ans = 0;
        for (auto it:mp) {
            ans += (it.second * (it.second - 1LL)) / 2LL;
        }

        cout << ans << endl;
    }

    return 0;
}







