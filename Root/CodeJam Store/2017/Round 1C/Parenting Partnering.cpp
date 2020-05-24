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

#define SZ 1500
#define SZ1 800

int dp[1444][722][2][2];
int mark1[SZ];
int mark2[SZ];

int solve (int day, int lft1, int lft2, int pre, int first) {
    if (day == -1) {
        if (lft1 == 0 && lft2 == 0) return (pre != first);
        return 1000000;
    }
    int &ret = dp[day][lft1][pre][first];
    if (ret != -1) return ret;
    ret = 100000;
    if (lft1 && !mark1[day]) {
        ret = min(ret, solve(day - 1, lft1 - 1, lft2, 0, day == 1439? 0: first) + (pre != 0));
    }
    if (lft2 && !mark2[day]) {
        ret = min(ret, solve(day - 1, lft1, lft2 - 1, 1, day == 1439? 1: first) + (pre != 1));
    }
    return ret;
}

int main() {
//    #if defined JESI
        freopen("B-large.in", "r", stdin);
        freopen("2.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        mem(mark1, 0);
        mem(mark2, 0);
        mem(dp, -1);

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            for (int j = x; j < y; j++) {
                mark1[j] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            for (int j = x; j < y; j++) {
                mark2[j] = 1;
            }
        }

        cout << "Case #" << cs + 1 << ": " << min(solve(1439, 720, 720, 0, 0), solve(1439, 720, 720, 1, 0)) << endl;
    }

    return 0;
}






