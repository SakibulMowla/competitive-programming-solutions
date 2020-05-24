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

int HI1, HI2;

ll calc (int n, vector <pll>& a, int one, int two) {
    ll cnt = 0;
    if (one > two) swap(one, two);
    for (int i = 0; i < n; i++) {
        if (a[i].X >= one && a[i].Y >= two) {
            cnt++;
        }
    }
    return cnt;
}

ll TSearch2 (int n, vector <pll>& a, int one) {
    int lo = 1, hi = HI2;
    int runs = 5;
    ll ans = 0;
    while (runs--) {
        int m1 = (2*lo + hi) / 3;
        int m2 = (lo + 2*hi) / 3;
        ll a1 = calc(n, a, one, m1) * (ll)m1;
        ll a2 = calc(n, a, one, m2) * (ll)m2;
        cout << ">> " << a1 << ' ' << a2 << ' ' << m1 << ' ' << m2 << endl;
        if (a1 > a2) {
            hi = m2;
            ans = max(ans, a1);
        } else {
            lo = m1;
            ans = max(ans, a2);
        }
    }
    return ans;
}

ll TSearch1 (int n, vector <pll>& a) {
    int lo = 1, hi = HI1;
    int runs = 5;
    ll ans = 0;
    while (runs--) {
        int m1 = (2*lo + hi) / 3;
        int m2 = (lo + 2*hi) / 3;
        ll a1 = TSearch2(n, a, m1) * (ll)m1;
        ll a2 = TSearch2(n, a, m2) * (ll)m2;
        cout << ">>>> " << a1 << ' ' << a2 << ' ' << m1 << ' ' << m2 << endl;
        if (a1 > a2) {
            hi = m2;
            ans = max(ans, a1);
        } else {
            lo = a1;
            ans = max(ans, a2);
        }
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <pll> a(n);
    multiset <ll> ms;

    for (auto &x: a) {
        cin >> x.X >> x.Y;
        if (x.X > x.Y) swap(x.X, x.Y);
        HI1 = max(HI1, (int)x.X);
        HI2 = max(HI2, (int)x.Y);
        ms.insert(x.Y);
    }

//    cout << TSearch1(n, a) << endl;

    sort(a.begin(), a.end());

    ll ans = 0;
    ll a1, a2;

    for (int i = 0; i < n; i++) {
        int j = 0;
        for (auto it: ms) {
            ll tmp = a[i].X * it * (ll)(n - i - j);
            if (tmp > ans) {
                ans = tmp;
                a1 = a[i].X;
                a2 = it;
            }
            j++;
        }
        ms.erase(ms.find(a[i].Y));
    }

    cout << ans << endl;
    cout << a1 <<  ' ' << a2 << endl;

    return 0;
}


