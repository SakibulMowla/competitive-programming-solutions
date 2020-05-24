#include "bits/stdc++.h"

using namespace std;

using pdd = pair <double, double>;

#define x first
#define y second

int main() {
	int n, cs = 0;
	while (cin >> n && n) {
		vector <pdd> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y;
		}	

		double ans = 1E9;
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double A = a[i].y - a[j].y;
				double B = -(a[i].x - a[j].x);
				double C = a[i].y * (a[i].x - a[j].x) - a[i].x * (a[i].y - a[j].y);

				int pos = 0, neg = 0;
				
				for (int k = 0; k < n; k++) if (k != i && k != j) {
					double d = A * a[k].x + B * a[k].y + C;
					if (d > 0) pos++;
					else if (d < 0) neg++;
				}

				if (pos != 0 && neg != 0) continue;

				for (int k = 0; k < n; k++) if (k != i && k != j) {
					double d = abs(A * a[k].x + B * a[k].y + C);
					d /= sqrt(A * A + B * B);
					ans = min(ans, d);
				}
			}
		}
		ans = ceil(ans * 100.0) / 100.0;

		cout << fixed << setprecision(2);
		cout << "Case " << ++cs << ": " << ans << endl;
	}
	return 0;
}
