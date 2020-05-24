#include <bits/stdc++.h>

using namespace std;

struct D {
	int n, m, q, cnt;
	unordered_map <string, int> mp;
	unordered_map <int, int> anti;
	vector <int> par;

	D (int n, int m, int q): n(n) , m(m), q(q), cnt(0), par(n) {
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			mp[s] = cnt++;
			par[i] = i;
		}

		for (int i = 0; i < m; i++) {
			int t;
			string s1, s2;
			cin >> t >> s1 >> s2;
			
			int a = mp[s1];
			int b = mp[s2];
			int x = find(a);
			int y = find(b);
			
			if (t == 1) {
				if (x == y) {
					cout << "YES" << endl;
				} else {
					if (anti.find(x) != anti.end() && anti[x] == y) {
						cout << "NO" << endl;
					} else {
						cout << "YES" << endl;
						par[x] = y;
						if (anti.find(x) != anti.end() && anti.find(y) != anti.end())
							par[anti[x]] = anti[y];
						else if (anti.find(x) != anti.end())
							anti[y] = anti[x], anti[anti[x]] = y;
					}
				}
			} else {
				if (anti.find(x) != anti.end() && anti[x] == y) {
					cout << "YES" << endl;
				} else {
					if (x == y) {
						cout << "NO" << endl;
					} else {
						cout << "YES" << endl;
						if (anti.find(x) != anti.end())
							par[anti[x]] = y;
						if (anti.find(y) != anti.end())
							par[anti[y]] = x;
						
						anti[x] = y;
						anti[y] = x;
					}
				}
			}
		}

		for (int i = 0; i < q; i++) {
			string s1, s2;
			cin >> s1 >> s2;

			int a = mp[s1];
			int b = mp[s2];
			int x = find(a);
			int y = find(b);

			if (x == y) cout << 1 << endl;
			else if (anti.find(x) != anti.end() && anti[x] == y) cout << 2 << endl;
			else cout << 3 << endl;
		}
	}

	int find (int r) {
		if (r == par[r]) return r;
		return par[r] = find(par[r]);
	}
};

int main () {
	ios::sync_with_stdio(false);

	int n, m, q;
	cin >> n >> m >> q;

	D DD(n, m, q);

	return 0;
}