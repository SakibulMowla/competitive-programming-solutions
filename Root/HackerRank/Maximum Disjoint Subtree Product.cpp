#include <bits/stdc++.h>

using namespace std;

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

#define SZ  110

struct Tree {     
	int n; // total nodes    
	vector < vector <int> > G; // adjacency list     
	vector <ll> w; // weights
	vector < vector <ll> > dp; // 0-th index the max subtree sum rooted at subtree i
				   // including node i
				   // 1-th index the max subtree sum rooted at subtree i
                   // not necessarily including node i
	Tree (int n): n(n), G(n, vector <int> ()), w(n), dp(n, vector <ll> (2, 0)) {
		for (auto &x: w) cin >> x;
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			G[u - 1].pb(v - 1);
			G[v - 1].pb(u - 1);
		}
	}

	ll solve () {
		ll ans = dfs(0, 0);
		ans = max(ans, dfsPar(0, 0, 0));
		for (auto &x: w) x = -x;
		dp = vector < vector <ll> > (n, vector <ll> (2, 0));
		ans = max(ans, dfs(0, 0));
		ans = max(ans, dfsPar(0, 0, 0));
		return ans;
	}

	ll dfs (int u, int p) {
		dp[u][0] = w[u];
		ll sub1 = 0, sub2 = 0;
		ll ans = 0;
		for (auto v: G[u]) {
			if (v != p) {
				ans = max(ans, dfs(v, u));
				dp[u][0] = max(dp[u][0], dp[u][0] + dp[v][0]);
				dp[u][1] = max(dp[u][1], dp[v][1]);
				if (dp[v][1] > sub2) {
					sub2 = dp[v][1];
					if (sub2 > sub1) swap(sub2, sub1);
				}
			}
		}
		dp[u][0] = max(0LL, dp[u][0]);
		dp[u][1] = max(dp[u][1], dp[u][0]);
		ans = max(ans, sub1 * sub2);
		return ans;
	}

	ll dfsPar (int u, int p, ll otherPart) {
		ll ans = dp[u][1] * otherPart;
		for (auto v: G[u]) {
			if (v != p) {
				ans = max(ans, dfsPar(v, u, max(0LL, otherPart + dp[u][0] - dp[v][0])));
			}
		}
		return ans;
	}
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	int n;
	cin >> n;

	Tree T(n);
	cout << T.solve() << endl;

    return 0;
}


