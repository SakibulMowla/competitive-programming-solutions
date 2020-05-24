#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pw(x) (1LL << (x))
#define sz(a) ((int)a.size())

typedef long long ll;

#define TASK "1"

const int M = (int) 1e9 + 7;

int G[301][100111];
int fa[333];


int main()
{
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    for (int n = 0; n <= 300; n++) for (int m = 0; m <= 100000; m++) {
        if (n == 0) {
            G[n][m] = (m == 0);
            continue;
        }
        if (m < n) {
            G[n][m] = 0;
        } else {
            G[n][m] = G[n][m - n] + G[n - 1][m - n];
            if (G[n][m] >= M) G[n][m] -= M;
        }
    }
    fa[0] = 1;
    for (int i = 1; i <= 300; i++) fa[i] = fa[i - 1] * 1ll * i % M;
    int t, n, m;
    cin >> t;
    while (t--) {
        scanf("%d%d", &n, &m);
        int ans = G[n][m] * 1ll* fa[n] % M;
        printf("%d\n", ans);
    }

    return 0;
}
