#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
									
using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)				
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

void insert_into_map(int indx, vector <int>&v, multimap < pair <int, int>, pair <int, int> >& mp) {
	do {
		mp.insert({{v[0], v[1]}, {v[2], indx}});
	} while (next_permutation(v.begin(), v.end()));
	return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector < vector <int> > sides(n, vector <int> (3));
	vector <int> indx;
	double ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> sides[i][0] >> sides[i][1] >> sides[i][2];
		sort(sides[i].begin(), sides[i].end());
		if (sides[i][0] / 2.0 > ans) {
			ans = sides[i][0] / 2.0;
			indx.clear();
			indx.pb(i);
		}
	}

	multimap < pair <int, int>, pair <int, int>> mp;
	for (int i = 0; i < n; i++) {
		insert_into_map(i, sides[i], mp);
	}

	int prex = -1, prey = -1;
	vector <int> best(2, -1), tindx(2, -1);

	for (auto& it: mp) {
		if (it.X.X == prex && it.X.Y == prey) {
			if (it.Y.X > best[0]) {
 				best[1] = best[0];
 				tindx[1] = tindx[0];
 				best[0] = it.Y.X;
 				tindx[0] = it.Y.Y;
 			} else if (it.Y.X > best[1]) {
				best[1] = it.Y.X;
				tindx[1] = it.Y.Y;
 			} 

 			double val = min((double)min(it.X.X / 2.0, it.X.Y / 2.0), (best[0] + best[1]) / 2.0);
 			if (val > ans) {
 				ans = val;
 				indx.clear();
 				indx.pb(tindx[0]);
 				indx.pb(tindx[1]);
 			}
		} else {
			best[0] = it.Y.X;
			tindx[0] = it.Y.Y;
			best[1] = -1;
			tindx[1] = -1;
		}
		prex = it.X.X;
		prey = it.X.Y;
	}

	cout << sz(indx) << endl;
	for (auto x: indx) {
		cout << x + 1 << ' ';
	}
	cout << endl;

    return 0;
}


