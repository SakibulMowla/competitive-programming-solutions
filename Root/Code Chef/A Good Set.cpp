#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int cs = 0; cs < t; cs++) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			if (i) cout << ' ';
			cout << 500 - i;
		}
		cout << endl;
	}

	return 0;
}