#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9 + 7;


#define SZ 102

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector < vector <int> > a(n, vector <int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                if (i == j && k) {
                    a[i][j] = 1;
                    k--;
                } else if (k >= 2) {
                    a[i][j] = a[j][i] = 1;
                    k -= 2;
                }
            }
        }
    }

    if (k == 0) {
        for (auto &x: a) {
            for (auto &y: x) {
                cout << y << ' ';
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}

