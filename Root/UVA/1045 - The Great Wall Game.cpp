#include "bits/stdc++.h"

using namespace std;

#define SZ 20

#define x first
#define y second

using pii = pair <int , int>;

pii point[SZ];
pii goal[SZ];

int dp[(1<<15)+10];
int col[(1<<15)+10];
int now;
int n;

int solve (int mask, int pos) {
	int &ret = dp[mask];
	if (col[mask] == now) return ret;
	col[mask] = now;
	if (!mask) return 0;

	ret = 1E9;
	for (int i = 0; i < n; i++) {
		if (mask & (1<<i)) {
			ret = min(ret, abs(point[pos].x - goal[i+1].x) + abs(point[pos].y - goal[i+1].y) + solve(mask & ~(1<<i), pos + 1));
		}
	}
	
	return ret;	
}

int main () {
	int test = 0;
	while (cin >> n && n) {
		for (int i = 1; i <= n; i++) {
			cin >> point[i].x >> point[i].y;
		}
		
		int ans = 1E9;
		//Same row, different columns
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				goal[j] = {i, j};
			}
			now++;
			ans = min(ans, solve((1<<n)-1, 1));
		}
		//Same column, different rows
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				goal[j] = {j, i};
			}
			now++;
			ans = min(ans, solve((1<<n)-1, 1));
		}
		//1st diagonal
		for (int i = 1; i <= n; i++) {
			goal[i] = {i, i};
		}
		now++;
		ans = min(ans, solve((1<<n)-1, 1));
		//2nd diagonal
		for (int i = 1; i <= n; i++) {
			goal[i] = {i, n-i+1};
		}
		now++;
		ans = min(ans, solve((1<<n)-1, 1));

		cout << "Board " << ++test << ": " << ans << " moves required."<< "\n\n";
	}
	return 0;
}



