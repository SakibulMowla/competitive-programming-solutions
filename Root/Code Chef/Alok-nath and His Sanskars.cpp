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

ll a[30];
vector <int> v;
ll Lim;
bool found;

bool bctk (int mask) {
    if (found) return true;
    if (mask == Lim) {
        found = true;
        return true;
    }
    for (int i = 0; i < sz(v); i++) {
        if ((mask|v[i]) == (mask+v[i]))
            bctk(mask|v[i]);
        if (found)
            return true;
    }
    return false;
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

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum == 0 || k == 1) {
            cout << "yes\n";
            continue;
        } else if (sum%(ll)k != 0) {
            cout << "no\n";
            continue;
        }

        int lim = (1<<n);
        ll need = sum / (ll)k;
        clr(v);

        for (int mask = 0; mask < lim; mask++) {
            ll tmp = 0;
            for (int i = 0; i < n; i++) if (mask & (1<<i)) {
                tmp += a[i];
            }
            if (tmp == need) v.pb(mask);
        }


        Lim = (1<<n) - 1;
        found = false;

        if (bctk(0)) cout << "yes\n";
        else cout << "no\n";
    }


    return 0;
}




