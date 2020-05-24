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
const ll mod = 1E9;


#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, k;
    while ( cin >> n >> k) {
        vector < vector <int> > mat (n + 1, vector <int> (n + 1, 0));

        int now = 0, ans = 0;
        for (int row = 1; row <= n; row++) {
            for (int col = 1; col < k; col++) {
                mat[row][col] = ++now;
            }
        }
        for (int row = 1; row <= n; row++) {
            for (int col = k; col <= n; col++) {
                mat[row][col] = ++now;
                if (col == k) {
                    ans += now;
                }
            }
        }

        cout << ans << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
    }


    return 0;
}





