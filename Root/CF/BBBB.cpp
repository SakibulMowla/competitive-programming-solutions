#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    ll b, q, l, m;
    cin >> b >> q >> l >> m;

    map <ll, bool> bad;
    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        bad[x] = true;
    }

    if (q == 0) {
        if (abs(b) > l) cout << 0 << endl;
        else {
            int cnt = 0;
            if (bad.find(b) == bad.end()) cnt = 1;
            if (bad.find(0) == bad.end()) cout << "inf" << endl;
            else cout << cnt << endl;
        }
    } else if (q == 1 || q == -1) {
        if (abs(b) > l) cout << 0 << endl;
        else {
            if (bad.find(b) == bad.end() || (q == -1 && bad.find(-b) == bad.end())) cout << "inf" << endl;
            else cout << 0 << endl;
        }
    } else {
        int cnt = 0;
        while (abs(b) <= l) {
            if (bad.find(b) == bad.end()) cnt++;
            b *= q;
        }
        cout << cnt << endl;
    }

    return 0;
}




