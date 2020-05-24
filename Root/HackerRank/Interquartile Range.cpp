#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

struct Quartile {
	int n;
	vector < pair <int, int> > a;

	Quartile (int n): n(n), a(n) {
		for (auto &x: a) cin >> x.X;
		int tot = 0;
		for (auto &x: a) cin >> x.Y, tot += x.Y;
		sort(a.begin(), a.end());
		//cout << findMedian(tot / 2 + (tot & 1), tot - 1) << endl;
		//cout << findMedian(0, tot / 2 - 1) << endl;
		cout << fixed << setprecision(1) << findMedian(tot / 2 + (tot & 1), tot - 1) - findMedian(0, tot / 2 - 1) << endl;
	}

	double findMedian (int i, int j) {
		int r = (j - i + 1);
		double median;
		if (r & 1) {
			median = element(i + r / 2);
		} else {
			median = (element(i + r / 2) + element(i + r / 2 - 1)) / 2.0;
		}
		return median;
	}

	int element (int p) {
		for (int i = 0, cnt = 0; i < n; i++) {
			cnt += a[i].Y;
			if (cnt > p) {
				return a[i].X;
			}
		}
        return 0;
	}
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    Quartile Q(n);

    return 0;
}






    