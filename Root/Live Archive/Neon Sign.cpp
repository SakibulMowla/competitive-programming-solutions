#include "bits/stdc++.h"

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

#define SZ  1010

int mat[SZ][SZ];

int nxt (int n, int N) {
    if (n > N) n = 1;
    return n;
}

int pre (int n, int N) {
    if (n < 1) n = N;
    return n;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cin >> mat[i][j];
                mat[j][i] = mat[i][j];
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == i || j == i + 1 || j == nxt(i + 2, n) || j == pre(i - 1, n)) continue;
                if (mat[i][j] == mat[i][i+1] && mat[i+1][j] == mat[i][i+1])
                    ans++/*, printf("> %d %d %d\n", i, i+1, j)*/;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (j == 1 || j == n || j == 2 || j == n - 1) continue;
            if (mat[1][j] == mat[1][n] && mat[n][j] == mat[1][n])
                ans++/*, printf(">> %d %d %d\n", 1, n, j)*/;
        }
        for (int i = 1; i <= n - 2; i++) {
            if (mat[i][i+1] == mat[i+1][i+2] && mat[i+1][i+2] == mat[i][i+2])
                ans++;
        }
        if (n > 3) {
            if (mat[n-1][n] == mat[n][1] && mat[n][1] == mat[n-1][1]) ans++;
            if (mat[n][1] == mat[1][2] && mat[1][2] == mat[n][2]) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}






