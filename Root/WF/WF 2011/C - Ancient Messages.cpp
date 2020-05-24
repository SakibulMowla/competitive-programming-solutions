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

#define SZ 210

int r, c;
int grid[SZ][SZ];
bool vis[SZ][SZ];
int compo[SZ][SZ];


//Coloring Outer 0's...
void dfs_color_outer (int p, int q) {
	vis[p][q] = 1;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) if (abs(dx + dy) == 1) {
			int np = p + dx;
			int nq = q + dy;
			if (np >= 0 && np <= r && nq >= 0 && nq <= c && grid[np][nq] == 0 && vis[np][nq] == 0) {
				dfs_color_outer (np, nq);
			}
		}
	}
	return;
}

int now;

int hole[40010];

//Coloring Connected 1 Components...
void dfs_color_ones (int p, int q) {
	vis[p][q] = 1;
	compo[p][q] = now;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) if (abs(dx + dy) == 1) {
			int np = p + dx;
			int nq = q + dy;
			if (np >= 0 && np <= r && nq >= 0 && nq <= c && grid[np][nq] == 1 && vis[np][nq] == 0) {
				dfs_color_ones (np, nq);
			}
			if (np >= 0 && np <= r && nq >= 0 && nq <= c && grid[np][nq] == 0 && vis[np][nq] == 0) {
				hole[now]++;
				dfs_color_outer (np, nq);
			}
		}
	}
	return;
}


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif
	
	map <char, int> mp = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'a', 10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15}};		
	
	int cs = 0;
	
	while (cin >> r >> c && (r || c)) {
		mem(grid, 0);
		mem(vis, 0);
		mem(compo, 0);
		mem(hole, 0);
		
		
		//Taking Input...
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				char ch;
				cin >> ch;
				for (int k = 0; k < 4; k++) {
					grid[i+1][j*4+k+1] = (bool)(mp[ch] & (1<<(3-k)));					
				}
			}			
		}
		
		r = r + 1;
		c = c * 4 + 1;
				
		dfs_color_outer(0, 0);
		
		now = 0;
		
		for (int i = 0; i <= r; i++) {
			for (int j = 0; j <= c; j++) {
				if (vis[i][j] == 0 && grid[i][j] == 1) {
					++now;
					dfs_color_ones(i, j);
				}
			}
		}
		
		string v;
		string s = "WAKJSD";
		
		for (int i = 1; i <= now; i++) {
			//assert (hole[i] <= 5);
			if (hole[i] <= 5) v.pb(s[hole[i]]);
		}
		
		sort(v.begin(), v.end());
		
		cout << "Case " << ++cs << ": " << v << '\n';
	}	

    return 0;
}






