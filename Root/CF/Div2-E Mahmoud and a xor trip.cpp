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

vector <int> adj[SZ];
ll a[SZ];
ll dp[SZ][21][2];
ll tmp[2];

void prepare (int u, int p) {
    for (int i = 0; i <= 20; i++) {
        dp[u][i][(a[u]>>i)&1]++;
    }

    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (v != p) {
            prepare(v, u);
            for (int j = 0; j <= 20; j++) {
                int bit = ((a[u]>>j)&1);
                dp[u][j][0] += dp[v][j][0^bit];
                dp[u][j][1] += dp[v][j][1^bit];
            }
        }
    }

    return;
}



ll solve (int u, int p) {
    ll ans = 0;

	if (u != p) {
		for (int j = 0; j <= 20; j++) {
			int bit = ((a[p] >> j) & 1);

			tmp[0] = dp[p][j][0] - dp[u][j][0 ^ bit];
			tmp[1] = dp[p][j][1] - dp[u][j][1 ^ bit];

			bit = ((a[u] >> j) & 1);
			ans += (tmp[bit ^ 1] * (1LL << j));

			dp[u][j][0] += tmp[0 ^ bit];
			dp[u][j][1] += tmp[1 ^ bit];
		}
	}

    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (v != p) {
            for (int j = 0; j <= 20; j++) {
				int bit = ((a[u] >> j) & 1);
                ans += (dp[v][j][bit^1] *  (1LL << j));
            }
			ans += solve(v, u);
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

    ll ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], ans += a[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    prepare(1, 1);
	cout << ans + solve(1, 1) / 2LL << endl;

    return 0;
}

