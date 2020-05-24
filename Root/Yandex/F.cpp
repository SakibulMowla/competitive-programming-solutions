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



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector < vector <int> > G(n + 1, vector <int>());

    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	G[u].pb(v);
    	G[v].pb(u);
    }

    vector < set <int> > ms;
    set <int> nset;

    for (int i = 1; i <= n; i++) {
    	bool isAdded = false;
    	for (int j = 0; j < sz(ms); j++) {
    		bool found = false;
    		for (auto &v: G[i]) {
    			if (ms[j].find(v) != ms[j].end()) {
    				found = true;
    				break;
    			}
    		}
    		if (found == false) {
    			ms[j].insert(i);
    			isAdded = true;
    			break;
    		}
    	}
    	if (isAdded == false) {
    		ms.push_back(nset);
    		ms[sz(ms) - 1].insert(i);
    	}
    }

    vector <int> ans(n + 1);

    for (int i = 0; i < sz(ms); i++) {
    	for (auto x: ms[i]) ans[x] = i + 1;
    }
	
	cout << sz(ms) << endl;
	for (int i = 1; i <= n; i++) {
		if (i > 1) cout << ' ';
		cout << ans[i];
	}
	cout << endl;

    return 0;
}




