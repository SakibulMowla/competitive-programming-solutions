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
const int inf = 1E8;
const ll mod = 1E9;

#define SZ 100010

int v1, v2, d;
int dp[110][2010];
int col[110][2010];

int solve (int sec, int speed) {
	if (speed < 0) return -inf;
	if (!sec) {
		if (speed == v2) return speed;
		return -inf;
	}
	
	int &ret = dp[sec][speed];
	if (col[sec][speed]) return ret;
	col[sec][speed] = 1;
	
	ret = -inf;
	for (int i = 0; i <= d; i++) {
		ret = max(ret, speed + solve(sec-1, speed + i));
		ret = max(ret, speed + solve(sec-1, speed - i));
	}
	
	return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	int t;
	while (cin >> v1 >> v2 >> t >> d) {
		mem(col, 0);
		cout << solve (t - 1, v1) << '\n'; 
	}


    return 0;
}






