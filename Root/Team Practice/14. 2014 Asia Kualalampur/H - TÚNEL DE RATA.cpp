#include "bits/stdc++.h"

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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

struct data {
    ll x, y, z;
};
data edge[SZ];

bool comp (data p, data q) {
    return p.z > q.z;
}

ll par[SZ];

void pre (int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
}

ll Find (ll r) {
    if (r == par[r]) return r;
    return par[r] = Find(par[r]);
}

pll MST (int n, int m) {
    pll ans = MP(0LL, 0LL);
    bool first = 0;

    for (int i = 0; i < m; i++) {
        ll u = edge[i].x, v = edge[i].y;
        u = Find(u); v = Find(v);

        if (u == v) {
            ans.X += edge[i].z;
            if (!first) {
                first = 1;
                ans.Y = edge[i].z;
            }
            continue;
        }

        par[u] = v;
    }

    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> edge[i].x >> edge[i].y >> edge[i].z;
        }

        sort (edge, edge+m, comp);
        pre (n);

        pll ans = MST(n, m);
        cout << "Case #" << cs+1 << ": " << ans.X << " " << ans.Y << '\n';
    }

    return 0;
}






