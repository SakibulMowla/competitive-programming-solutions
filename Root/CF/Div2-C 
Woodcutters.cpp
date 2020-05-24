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
using VI = vector < int >;
using VVI = vector < VI >;
using VP = vector < pii >;
const int inf = 1E7;
const ll mod = 1E9;

#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	FAST

	int n;
	cin >> n;
	
	VVI dp(n + 1, VI(3, -inf));
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	
	VP a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	
	int preX = -2E9, preH = 0;
	for (int i = 1; i <= n; i++) {
		int nowX = a[i].first, nowH = a[i].second;
		int nextX;
		if (i != n) nextX = a[i+1].first;
		else nextX = 2E9 + 1;
		for (int j = 0; j < 3; j++) {
			if (dp[i - 1][j] != -inf) {
				int last = preX;
				if (j == 2) last += preH;
				
				dp[i][0] = max(dp[i][0], dp[i-1][j]);
				if (nowX - nowH > last) dp[i][1] = max(dp[i][1], 1 + dp[i-1][j]);
				if (nowX + nowH < nextX) dp[i][2] = max(dp[i][2], 1 + dp[i-1][j]);
			}
		}
		preX = nowX, preH = nowH;
	}

	cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
	
    return 0;
}

/*
10
999999900 1000000000
999999901 1000000000
999999902 1000000000
999999903 1000000000
999999904 1000000000
999999905 1000000000
999999906 1000000000
999999907 1000000000
999999908 1000000000
999999909 1000000000
*/




