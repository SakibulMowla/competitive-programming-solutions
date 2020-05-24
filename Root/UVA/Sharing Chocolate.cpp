#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 20

int a[SZ];
int ones[(1<<15)+10];
int sum[(1<<15)+10];

int dp[110][(1<<15)+10];
int col[110][(1<<15)+10];
int now;

int solve (int x, int y, int mask) {
	int &ret = dp[x][mask];
	if (col[x][mask] == now) return ret;
	col[x][mask] = now;
	
	if (ones[mask] == 1) {
		return ret = (x * y == sum[mask]);
	}
	
	int rtmp = 0;
	int tmp = mask;
	
	while (tmp) {
		tmp = ((tmp - 1) & mask);
		
		for (int i = 1; i <= x - 1; i++) {
			if (i * y == sum[tmp] && (x - i) * y == sum[mask ^ tmp])
				rtmp = (solve (i, y, tmp) && solve (x - i, y, mask ^ tmp));
			if (rtmp) goto HELL;
		}
		
		for (int i = 1; i <= y - 1; i++) {
			if (i * x == sum[tmp] && (y - i) * x == sum[mask ^ tmp])
				rtmp = (solve (x, i, tmp) && solve (x, y - i, mask ^ tmp));
			if (rtmp) goto HELL;
		}	
	}
	
	HELL:;
	return ret = rtmp;	
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif
	
	FAST
	
	int Lim = (1<<15);
	for (int mask = 0; mask < Lim; mask++) {
		for (int i = 0; i < 15; i++) {
			if (mask & (1<<i))
				ones[mask]++;
		}
	}
	
	int cs = 0, n;
	while (cin >> n && n) {
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		mem(sum, 0);
		int lim = (1<<n);
		
		for (int mask = 0; mask < lim; mask++) {
			for (int i = 0; i < n; i++) 
				if (mask & (1<<i)) 
					sum[mask] += a[i];
		}
		
		if (sum[lim-1] != x * y) {
			cout << "Case " << ++cs << ": No" << '\n';
		} else {
			++now;
			if (solve (x, y, lim - 1)) cout << "Case " << ++cs << ": Yes" << '\n';
			else cout << "Case " << ++cs << ": No" << '\n';			
		}
	}


    return 0;
}






