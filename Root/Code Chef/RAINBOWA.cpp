#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int cs = 0; cs < t; cs++) {
		int n;
		cin >> n;

		vector <int> a(n);
		for (auto &x: a) cin >> x;

		int last = 0;
		bool flag = (a[0] == 1 && a[n / 2] == 7);

		for (int i = 0; i < (n + 1) / 2; i++) {
			if (a[i] < last || (a[i] - last > 1) || a[i] != a[n - i - 1] || a[i] > 7 || a[i] < 1) {
				flag = false;
				break;
			}
			last = a[i];
		}

		cout << (flag ? "yes" : "no") << endl;
	}

	return 0;
}