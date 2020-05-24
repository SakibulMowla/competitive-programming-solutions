#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010

int num[SZ];
vector <pii> v;

ll calc (ll a, ll b) {
    ll res = b * (b + 1LL) / 2LL;
    --a;
    res -= a * (a + 1LL) / 2LL;
    return res;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        num[0] = 0;
        for (int i = 1; i <= k; i++) {
            cin >> num[i];
        }

        sort (num, num + k + 1);

        ll sum = 0LL;
        clr(v);

        v.pb(MP(0, 0));
        for (int i = 1; i <= k; i++) {
            ll lo = num[i-1] + 1;
            ll hi = num[i] - 1;

            if (lo <= hi) {
                sum += calc(lo, hi);
                v.pb(MP(lo, sum));
            }
        }
        v.pb(MP(sum+2, sum+2));

        ll point = -1;
        for (int i = 1; i < sz(v); i++) {
            cout << "> " << v[i].X << " " << v[i].Y << '\n';
            if (v[i].X - v[i-1].Y > 1) {
                point = v[i-1].Y + 1;
                break;
            }
        }

        assert(point == -1);

        if (point % 2 == 0) {
            cout << "Mom\n";
        } else {
            cout << "Chef\n";
        }
    }


    return 0;
}




