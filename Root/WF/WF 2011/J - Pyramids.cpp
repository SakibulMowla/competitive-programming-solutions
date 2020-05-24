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

using pii = pair < pair <int , int>, int>;
using pll = pair <ll , ll>;
const int inf = 100000;
const ll mod = 1E9;

#define SZ 100010

struct data {
	int cubes;
	int base;
	char type;
	data (int a, int b, char c) {
		cubes = a, base = b, type = c;
	}
};

bool comp (data a, data b) {
	if (a.cubes == b.cubes) {
		return a.type < b.type;
	}
	return a.cubes > b.cubes;
}

vector <data> v;
ll nxt[1000010];
int dp[1000010];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


	//Regular High Pyramids...
	int sum = 1;
	for (int i = 2; ; i++) {
		sum += i * i;
		if (sum > 1E6) break;
		v.pb(data(sum, i, 'H'));
	}

	//Odd Low Pyramids...
	sum = 1;
	for (int i = 3; ; i+=2) {
		sum += i * i;
		if (sum > 1E6) break;
		v.pb(data(sum, i, 'L'));
	}

	//Even Low Pyramids...
	sum = 4;
	for (int i = 4; ; i+=2) {
		sum += i * i;
		if (sum > 1E6) break;
		v.pb(data(sum, i, 'L'));
	}

	sort (v.begin(), v.end(), comp);
	reverse (v.begin(), v.end());

	dp[0] = 0;
	for (int i = 1; i <= 1000000; i++) {
		dp[i] = inf;
	}

    int tot = sz(v);

	for (int i = 0; i < tot; i++) {
		for (int j = 1000000; j >= v[i].cubes; j--) {
			if (dp[j - v[i].cubes] + 1 <= dp[j]) {
				dp[j] = dp[j - v[i].cubes] + 1;
				nxt[j] = (nxt[j - v[i].cubes] << 9LL) | (i+1);
			}
		}
	}

	int n, cs = 0;

	while (scanf("%d", &n) && n) {
		int ans = dp[n];
		if (ans == inf) {
			printf("Case %d: impossible\n", ++cs);
		} else {
			printf("Case %d:", ++cs);
			vector <data> ans;
			ll now = nxt[n];
			for (int i = 0; i < 6; i++) {
                int idx = (now & (ll)511) - 1;
                if (idx >= 0) {
                    ans.pb(v[idx]);
                }
                now >>= 9LL;
			}
			sort(ans.begin(), ans.end(), comp);
			for (int i = 0; i < sz(ans); i++) {
                printf(" %d%c", ans[i].base, ans[i].type);
			}
			printf("\n");
		}
	}

    return 0;
}


/*
213
Case 1: 7L 5H 5L 4L 3H 2H
216
Case 2: 7H 6L 4L
262
Case 1: 6H 6L 5H 5L 4L 2H
*/



