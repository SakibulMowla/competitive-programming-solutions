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
const ll mod = 1000000007;

#define SZ  2010

int mark[SZ][SZ];
int par[SZ];

int Find (int r) {
    if (r == par[r]) return r;
    return par[r] = Find(par[r]);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++) {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int l, r;
            scanf("%d %d", &l, &r);

            for (int j = l, k = r; j < k && mark[j][k] != cs; j++, k--) {
                mark[j][k] = cs;
                int x = Find(j);
                int y = Find(k);
                if (x != y) {
                    par[x] = y;
                }
            }
        }

        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            if (par[i] == i) {
                ans = (ans * 26LL) % mod;
            }
        }

        cout << ans << endl;
    }

    return 0;
}




