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

int par[SZ];

inline int _find (int r) {
    return (r == par[r]) ? r : (par[r] = _find(par[r]));
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        par[u] = v;
    }

    for (int i = 1; i <= n; i++) {
        cout << _find(i) << ' ';
    }
    cout << '\n';


    return 0;
}






