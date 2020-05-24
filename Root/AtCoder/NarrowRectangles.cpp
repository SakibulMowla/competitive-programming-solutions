#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, int>> vp(n);
	for (auto &x: vp) cin >> x.first >> x.second;

	vector<vector<int>> store(n, vector<int>(401, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 400; j++) {
			int tmp;
			if (j >= vp[i].first && j <= vp[i].second) tmp = 0;
			else tmp = min(abs(j - vp[i].first), abs(j - vp[i].second));
			store[i][j] = tmp + (i ? store[i - 1][j] : 0);
		}
	}

 	cout << *min_element(store[n - 1].begin(), store[n - 1].end()) << endl;

	return 0;
}