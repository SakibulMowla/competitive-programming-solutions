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

    int n, a, b;
    cin >> n >> a >> b;

    queue <int> q;
    vector <bool> mark(2010, false);

    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	mark[x] = true;
    }

    bool isstart = true;

    for (int i = 1; i <= 2000; i++) {
    	if (mark[i] == true) q.push(i);
    	if (sz(q) >= a || (!q.empty() && i - q.front() >= b)) {
    		int k = (q.size() + 1) / 2;
    		for (int j = 0; j < k; j++) {
    			if (!isstart) cout << ' ';
    			isstart = false;
    			cout << i;
    			q.pop();
    		}
    	} 
    }
    cout << endl;

    return 0;
}




