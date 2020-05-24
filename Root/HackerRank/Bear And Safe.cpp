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

#define SZ  100010

vector <int> tmp;

ll calc (int n, vector <ll> &a) {
    vector <ll> shift(n, 0);
    ll best = 0;

    for (int i = n; i < n + n; i++) {
        for (int j = i - 1, k = 1; k < n; j--, k++) {
            shift[i - j] += abs(a[i] - a[j]);
            best = max(best, shift[i - j]);
        }
    }

    clr(tmp);
    for (int i = 0; i < n; i++) {
        if (shift[i] == best) {
            tmp.pb(i);
        }
    }

    return best;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <ll> a(n+n);
    vector <int> indx;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
        if (a[i] == 0) {
            indx.pb(i);
        }
    }

    int lim = (1<<(sz(indx))) - 1;
    ll best = -1;
    vector <int> ans;

    for (int mask = 0; mask < lim; mask++) {
        for (int j = 0; j < sz(indx); j++) {
            if (mask & (1<<j)) {
                a[indx[j]] = 1E9;
            } else {
                a[indx[j]] = 1;
            }
        }

        ll val = calc(n, a);

        if (sz(tmp) > sz(ans)) {
            best = val;
            ans = tmp;
        }
    }

    if (lim == 0) {
        calc(n, a);
        ans = tmp;
    }

    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}



