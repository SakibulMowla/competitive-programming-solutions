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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    vector < vector <int> > grid(n, vector <int> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector <int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        int tmp = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                tmp++;
                ans[i] = max(ans[i], tmp);
            } else {
                tmp = 0;
            }
        }
    }

    for (int cs = 0; cs < q; cs++) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        grid[r][c] ^= 1;

        ans[r] = 0;
        int tmp = 0;
        for (int i = 0; i < m; i++) {
            if (grid[r][i] == 1) {
                tmp++;
                ans[r] = max(ans[r], tmp);
            } else {
                tmp = 0;
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, ans[i]);
        }

        cout << res << endl;
    }


    return 0;
}







