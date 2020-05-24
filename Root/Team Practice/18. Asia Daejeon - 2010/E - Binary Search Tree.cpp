#include <bits/stdc++.h>

using namespace  std;

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
const ll mod = 9999991LL;

#define SZ  110

struct data {
    int val, lft, rht;
};

data a[SZ];
int node;
int strt[SZ], endd[SZ];

void dfs (int u, int now) {
//    cout << ">>> dfs1 " << u << " " << now << endl;
    if (a[u].val == -1) {
        a[u].val = now;
        return;
    }
    if (now < a[u].val) {
        if (a[u].lft == -1) a[u].lft = ++node;
        dfs(a[u].lft, now);
    } else {
        if (a[u].rht == -1) a[u].rht = ++node;
        dfs(a[u].rht, now);
    }
    return;
}

int dfs2 (int u, int cnt) {
    strt[u] = cnt;
    endd[u] = 0;
    if (a[u].lft != -1) endd[u] += dfs2(a[u].lft, cnt+1);
    if (a[u].rht != -1) endd[u] += dfs2(a[u].rht, cnt+1);
    return endd[u] + 1;
}

ll dp[1048576+100];
int col[1048576+10];
int now;

ll solve (int mask, int tym) {
    ll &ret = dp[mask];
    if (col[mask] == now) return ret;
    col[mask] = now;
    if (!mask) return ret = 1LL;

    ret = 0LL;
    for (int i = 0; i <= node; i++) if (mask & (1<<i)) {
        if (strt[i] <= tym && endd[i] >= tym) {
            ret = ret + solve(mask&~(1<<i), tym+1);
            if (ret >= mod) ret -= mod;
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
//    cin >> t;
    scanf("%d", &t);
    for (int cs = 0; cs < t; cs++) {
        int n;
//        cin >> n;
        scanf("%d", &n);

        node = 0;
        for (int i = 0; i < n; i++) {
            a[i].lft = a[i].rht = a[i].val = -1;
        }

        for (int i = 0; i < n; i++) {
            int val;
//            cin >> val;
            scanf("%d", &val);
            dfs(0, val);
        }

        dfs2(0, 1);

        for (int i = 0; i < n; i++) {
            endd[i] = n - endd[i];
        }

//        for (int i = 0; i < n; i++) {
//            cout << ">>" << strt[i] << "   " << endd[i] << endl;
//        }
        now++;
        printf("%lld\n", solve((1<<n)-1, 1));
//        cout << solve((1<<n)-1, 1) << '\n';
    }

    return 0;
}






