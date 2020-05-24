#include "bits/stdc++.h"

using namespace std;

using pii = pair <int, int>;

#define SZ 22

#define x first
#define y second

int people[SZ];
pii component[SZ];

int main() {
	int test = 0;
	int n, m;
	
	while (cin >> n >> m && (n || m)) {
		for (int i = 0; i < n; i++) {
			cin >> people[i];
		}
		
		int collisions;
		cin >> collisions;
		for (int i = 0; i < collisions; i++) {
			int volume;
			cin >> volume;
			int mask = 0;
			for (int j = 0; j < volume; j++) {
				int x;
				cin >> x;
				--x;
				mask |= (1<<x);
			}
			int count;
			cin >> count;
			component[i] = {mask, count};
		}

		int ans = -1;
		int towers;
		int lim = (1 << n);
		
		for (int mask = 0; mask < lim; mask++) {
			if (__builtin_popcount(mask) == m) {
				int tmp = 0;
				for (int i = 0; i < n; i++) {
					if (mask & (1<<i)) {
						tmp += people[i];
					}
				}

				for (int i = 0; i < collisions; i++) {
					int common = (component[i].x & mask);
					if (__builtin_popcount(common)) {
						tmp -= component[i].y * (__builtin_popcount(common) - 1);
					}
				}

				if (tmp > ans) {
					ans = tmp;
					towers = mask;
				}
			}
		}

		cout << "Case Number  " << ++test << '\n';
		cout << "Number of Customers: " << ans << '\n';
		cout << "Locations recommended:";
		for (int i = 0; i < n; i++) {
			if (towers & (1<<i)) {
				cout << ' ' << i + 1;
			}
		}
		cout << "\n\n";
	}
	
	return 0;
}

