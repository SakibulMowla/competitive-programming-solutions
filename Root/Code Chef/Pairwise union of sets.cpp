#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007;

#define SZ  100010

struct data {
	int len;
	vector <int> a;
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    vector <data> v(2500);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
    	int n, k;
    	cin >> n >> k;

    	for (int i = 0; i < n; i++) {
    		cin >> v[i].len;
    		v[i].a = vector <int> (v[i].len);
    		for (auto &x: v[i].a) cin >> x;
    		sort(v[i].a.begin(), v[i].a.end());
    	}

    	int ans = 0;

    	for (int i = 0; i < n; i++) {
    		for (int j = i + 1; j < n; j++) {
    			int p = 0, q = 0, needed = 1;
    			bool flag = true;
    			while (p < v[i].len && q < v[j].len) {
    				if (v[i].a[p] < v[j].a[q]) {
    					if (v[i].a[p] == needed) needed++;
    					else if (v[i].a[p] > needed) {
    						flag = false;
    						break;
    					}
    					p++;
    				} else {
    					if (v[j].a[q] == needed) needed++;
    					else if (v[j].a[q] > needed) {
    						flag = false;
    						break;
    					}
    					q++;
    				}
    			} 
    			if (flag == true) {
    				while (p < v[i].len) {
    					if (v[i].a[p] == needed) needed++;
    					else if (v[i].a[p] > needed) {
    						flag = false;
    						break;
    					}
    					p++;
    				}
    			}
    			if (flag == true) {
    				while (q < v[j].len) {
    					if (v[j].a[q] == needed) needed++;
    					else if (v[j].a[q] > needed) {
							flag = false;
							break;
						}
						q++;
    				}
    			}
    			if (needed == k + 1) ans++;
    		}
    	}

    	cout << ans << endl;
    }

    return 0;
}



/*
3
2 2
1 1
1 1
3 2
2 1 2
2 1 2
2 1 2
3 4
3 1 2 3
4 1 2 3 4
3 2 3 4
*/