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
const ll mod = 1E9;


#define SZ 100010

ll f(ll n) {
    return n * (n + 1) / 2;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    ll n = sz(s);
    ll ans = f(n);

    vector<ll> cnt(26, 0);
    for (auto x: s) cnt[x - 'a']++;

    for (int i = 0; i < 26; i++) {
        ans -= f(cnt[i]);
    }

    cout << ans + 1 << endl;

    return 0;
}




