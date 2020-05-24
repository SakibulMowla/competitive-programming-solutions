#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010

struct data {
    int p, q;
};

data a[110];

bool comp (data x, data y) {
    return x.p < y.p;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].p;
        a[i].q = i;
    }

    sort (a+1, a+n+1, comp);

    vector <int> v;

    for (int i = 1; i <= n; i++) {
        if (k - a[i].p >= 0) {
            k -= a[i].p;
            v.pb(a[i].q);
        } else {
            break;
        }
    }

    cout << sz(v) << '\n';
    for (int i = 0; i < sz(v); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}






