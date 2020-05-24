//#include <bits/stdc++.h>

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

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

const ll inf = -4E18;
const ll mod = 1E9;


#define SZ 100010

ll dp[4][SZ];
bool vis[4][SZ];
ll a[4];
ll b[SZ];
int n;

ll solve(int p, int q) {
	if (p == 3) return 0;
	if (q == n) return inf;

	ll& ret = dp[p][q];
	if (vis[p][q] == true) return ret;

	vis[p][q] = true;
	ret = solve(p, q + 1);
	ret = max(ret, a[p] * b[q] + solve(p + 1, q));
	if (ret < inf) ret = inf;

	return ret;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    cin >> n >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < n; i++) cin >> b[i];

    mem(vis, false);
	cout << solve(0, 0) << endl;

    return 0;
}




