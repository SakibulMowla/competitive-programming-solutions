#include <bits/stdc++.h>

using namespace std;

#define SZ 102

int a[SZ], b[SZ];
int ok[SZ][2*SZ*SZ];
int dp[SZ][2*SZ*SZ];

int isOK(int indx, int empty) {
	if (indx == 0) return (empty >= 10000)? 0: -1000000;
	
	int &ret = ok[indx][empty];
	if (ret != -1) return ret;

	ret = max(isOK(indx - 1, empty + b[indx] - a[indx]), 1 + isOK(indx - 1, empty - a[indx]));

	return ret;
}

int solve(int indx, int empty) {
	if (indx == 0) return (empty >= 10000)? 0: 100000;

	int &ret = dp[indx][empty];
	if (ret != -1) return ret;

	ret = 100000;
	if (isOK(indx - 1, empty + b[indx] - a[indx]) == ok[indx][empty]) ret = solve(indx - 1, empty + b[indx] - a[indx]);
	if (isOK(indx - 1, empty - a[indx]) + 1 == ok[indx][empty]) ret = min(ret, a[indx] + solve(indx - 1, empty - a[indx]));

	return ret;
}

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	memset(dp, -1, sizeof dp);
	memset(ok, -1, sizeof ok);

	cout << n - isOK(n, 10000) << ' ';
	cout << solve(n, 10000) << endl;

	return 0;
}

/*

4
3 3 4 3
4 7 6 5

2 6

2
1 1
100 100

1 1

5
10 30 5 6 24
10 41 7 8 24

3 11


1
1
100

10
18 42 5 1 26 8 40 34 8 29
18 71 21 67 38 13 99 37 47 76

3 100
*/