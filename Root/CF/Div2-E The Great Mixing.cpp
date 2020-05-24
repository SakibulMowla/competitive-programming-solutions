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


#define SZ 2002


int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector <bool> concentration (SZ, false);
    queue <int> q;
    vector <int> dist(SZ, numeric_limits<int>::max());
    
    for (int i = 0; i < k; i++) {
    	int x;
    	cin >> x;
    	if (concentration[x] == false) {
    		concentration[x] = true;
    		q.push(x - n + 1000);
    		dist[x - n + 1000] = 1;
    	}
    }

    while (!q.empty()) {
    	int x = q.front(); q.pop();
    	for (int i = 0; i <= 1000; i++) {
    		if (concentration[i]) {
    			int nx = x + i - n;
    			if (nx >= 0 && nx <= 2000 && dist[nx] > dist[x] + 1) {
    				dist[nx] = dist[x] + 1;
    				q.push(nx);
    			}
    		}
    	}
    }

    if (dist[1000] == numeric_limits<int>::max()) cout << -1 << endl;
    else cout << dist[1000] << endl;

    return 0;
}
