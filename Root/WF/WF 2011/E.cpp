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

#define SZ 2010

int a[SZ][SZ];
int R, C;

int f (int x, int y) {
	x = min(x, R);
	y = min(y, C);
	
	x = max(x, 0);
	y = max(y, 0);
	
	return a[x][y];
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif
	
	FAST	
	
	int r, c, n, q, cs = 0;
	
	while (cin >> r >> c >> n >> q && (r || c || n || q)) {
		mem(a, 0);
		
		for (int i = 0; i < n; i++) {
			int p, q;
			cin >> p >> q;
			--p, --q;
			a[p + q + 1][p - q + c] = 1;
		}		
		
		R = C = r + c - 1;
		
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];	
			}
		}
		
		
		pii best;
		
		cout << "Case " << ++cs << ":" << endl;			
		for (int t = 0; t < q; t++) {
			int m;
			cin >> m;

			int ans = 0;
			best = {0, 0};
			for (int i = 1; i <= R; i++) {
				for (int j = 1 - ((i + c) & 1); j <= C; j += 2) {
					int v = f (i+m, j+m) - f (i-m-1, j+m) - f(i+m, j-m-1) + f(i-m-1, j-m-1);
					pii tmp = {(i + j - c - 1) / 2, (i - j + c - 1) / 2};

					if (v >= ans) {
						if (tmp.X >= 0 && tmp.X < r && tmp.Y >= 0 && tmp.Y < c) {
							swap(tmp.X, tmp.Y);
							if (v > ans) {
								best = tmp;
							} else {   
								best = min(tmp, best);
							}
							ans = v;
						}
					}	
				} 
			}
			
			cout << ans << " (" << best.Y + 1 << "," << best.X + 1 << ")" << '\n';
		}
	}

    return 0;
}






