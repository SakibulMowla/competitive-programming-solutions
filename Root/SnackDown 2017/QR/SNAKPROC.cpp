#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int cs = 0; cs < t; cs++) {
		string s;
		int n;
		cin >> n >> s;

		int cur = 0;
		bool flag = true;

		for (auto x: s) {
			if (x == 'H') {
				if (cur != 0) {
					flag = false;
					break;
				}
				cur ^= 1;
			} else if (x == 'T') {
				if (cur != 1) {
					flag = false;
					break;
				}
				cur ^= 1;
			}
		} 
		if (cur != 0) flag = false;
	
		cout << (flag ? "Valid": "Invalid") << endl;
	}

	return 0;
}