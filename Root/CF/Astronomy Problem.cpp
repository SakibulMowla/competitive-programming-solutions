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

struct data {
    ll a, b, c;
    data (ll a, ll b, ll c): a(a), b(b), c(c) {}
    bool operator < (const data &x) const {
        return (a < x.a || (a == x.a && b < x.b) || (a == x.a && b == x.b && c < x.c));
    }
};

int main() {
//    #if defined JESI
        freopen("astronomy.in", "r", stdin);
        freopen("astronomy.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <pll> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].X >> v[i].Y;
    }

    int m;
    cin >> m;

    map <data, int> mp;
    vector <ll> A(m), B(m), C(m);

    for (int i = 0; i < m; i++) {
//        ll a, b, c;
        cin >> A[i] >> B[i] >> C[i];
        if (A[i] > B[i]) {
            swap(A[i], B[i]);
        }
        mp[data(A[i], B[i], C[i])] = 0;
    }

//    vector <int> ans(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) if (i != j) {
            ll a = v[i].X * v[i].X + v[i].Y * v[i].Y;
            ll b = v[j].X * v[j].X + v[j].Y * v[j].Y;
            ll c = (v[i].X - v[j].X) * (v[i].X - v[j].X) + (v[i].Y - v[j].Y) * (v[i].Y - v[j].Y);
            if (a > b) {
                swap(a, b);
            }
            if (mp.find(data(a, b, c)) != mp.end()) {
                mp[data(a, b, c)]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << mp[data(A[i], B[i], C[i])] << endl;
    }

    int x;
    cin >> x;

    return 0;
}




