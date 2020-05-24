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

struct data {
    ll x, y, r;
};

bool comp (data p, data q) {
    return p.r < q.r;
}

ll dp[1010][2][2];
bool col[1010][2][2];

ll solve (int n, int m1, int m2, vector <data>& a, vector < vector <int> >& G) {
    ll &ret = dp[n][m1][m2];
    if (col[n][m1][m2] != 0) return ret;
    col[n][m1][m2] = 1;

    ll ret1 = m1? -a[n].r * a[n].r : a[n].r * a[n].r;
    ll ret2 = m2? -a[n].r * a[n].r : a[n].r * a[n].r;

    for (auto v: G[n]) {
        ret1 += solve(v, !m1, m2, a, G);
        ret2 += solve(v, m1, !m2, a, G);
    }

    return ret = max(ret1, ret2);
}

void dfs (int u, vector < vector <int> >& G, vector <bool>& mark) {
    mark[u] = true;
    for (auto v: G[u]) {
        if (!mark[v]) dfs(v, G, mark);
    }
    return;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <data> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }

    sort(a.begin(), a.end(), comp);

    vector < vector <int> > G(n, vector <int> ());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
            if ((double)a[j].r >= d + (double)a[i].r) {
                G[j].pb(i);
                break;
            }
        }
    }

    stack <int> stk;
    vector <bool> mark(n, false);

    for (int i = n - 1; i >= 0; i--) {
        if (!mark[i]) {
            dfs(i, G, mark);
            stk.push(i);
        }
    }

    mark = vector <bool> (n, false);
    double ans = 0;

    while (!stk.empty()) {
        int u = stk.top(); stk.pop();
        if (!mark[u]) {
            dfs(u, G, mark);
            ans += solve(u, 0, 0, a, G);
        }
    }

    cout << fixed << setprecision(15) << ans * acos(0) * 2.0 << endl;

    return 0;
}

