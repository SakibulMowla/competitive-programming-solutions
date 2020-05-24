#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ 72

int mat[SZ][SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int row = 0;
            for (int j = 1; j <= n; j++) {
                cin >> mat[i][j];
                row ^= mat[i][j];
                mat[i][j] = row ^ mat[i-1][j];
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int p = i; p <= n; p++) {
                    for (int q = j; q <= n; q++) {
                        int now = mat[p][q];
                        now ^= mat[i-1][q];
                        now ^= mat[p][j-1];
                        now ^= mat[i-1][j-1];
                        if (now > ans) {
                            ans = now;
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}





