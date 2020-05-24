#include <bits/stdc++.h>

using namespace std;

using PII = pair <int, int>;
using PIII = pair <PII, int>;
using VI = vector <int>;
using VVI = vector <VI>;
using VP = vector <PIII>;

#define X first
#define Y second

PIII par;

bool comp (PIII a, PIII b) {
	return (a.X.X - par.X.X) * (b.X.Y - par.X.Y) > (b.X.X - par.X.X) * (a.X.Y - par.X.Y);
}

struct GEO {
	int n;
	VVI G;
	VP points;
	VI subSize;
	VI ans;

	GEO (int n): n(n), G(n, VI()), points(n), subSize(n, 1), ans(n) {
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			G[u - 1].push_back(v - 1);
			G[v - 1].push_back(u - 1);
		}
		
		int cnt = 0;
		for (auto &p: points) {
			cin >> p.X.X >> p.X.Y;
			p.Y = cnt++;
		}
		
		getSZ(0, 0);
		solve(0, 0, 0, n);

		for (int i = 0; i < n; i++) {
			if (i) cout << ' ';
			cout << ans[i] + 1;
		}
		cout << endl;
	}

	void getSZ (int u, int p) {
		for (auto v: G[u]) {
			if (v != p) {
				getSZ(v, u);
				subSize[u] += subSize[v];
			}
		}
		return;
	}

	void solve (int u, int p, int from, int to) {
		for (int i = from + 1; i < to; i++) {
			if (points[from].X.X > points[i].X.X || (points[from].X.X == points[i].X.X && points[from].X.Y > points[i].X.Y)) {
				swap(points[from], points[i]);
			}
		}

		ans[u] = points[from].Y;

		par = points[from];
		sort(points.begin() + from + 1, points.begin() + to, comp);

		for (auto v: G[u]) {
			if (v != p) {
				solve(v, u, from + 1, from + subSize[v] + 1);
				from += subSize[v];
			}
		}

		return;
	}
};


int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	GEO NPM(n);

	return 0;
}