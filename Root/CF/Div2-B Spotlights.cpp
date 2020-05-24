#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector < vector <int> > mat(n, vector <int> (m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1) {
				for (int k = j + 1; k < m; k++) {
					if (mat[i][k] == 0) {
						ans++;
					}
				}
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			if (mat[i][j] == 1) {
				for (int k = j -1; k >= 0; k--) {
					if (mat[i][k] == 0) {
						ans++;
					}
				}
				break;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (mat[i][j] == 1) {
				for (int k = i + 1; k < n; k++) {
					if (mat[k][j] == 0) {
						ans++;
					}
				}
				break;
			}
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (mat[i][j] == 1) {
				for (int k = i - 1; k >= 0; k--) {
					if (mat[k][j] == 0) {
						ans++;
					}
				}
				break;
			}
		}
	}

	cout << ans << endl;

    return 0;
}

 