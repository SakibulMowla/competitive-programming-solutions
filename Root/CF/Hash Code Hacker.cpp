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


ll POW (ll b, ll p) {
    ll res = 1;
    for (int i = 0; i < p; i++) {
        res *= b;
    }
    return res;
}

int main() {
//    #if defined JESI
        freopen("hash.in", "r", stdin);
        freopen("hash.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << ((i & (1<<j)) ? "Hs": "IT");
        }
        cout << endl;
    }

    return 0;
}





