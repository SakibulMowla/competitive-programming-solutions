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


#define SZ 510

int a[SZ];
int dp[SZ][SZ][2];

int solve (int st, int nd, int now) {
    if (st > nd) return 0;
    if (st == nd) return now;

    int &ret = dp[st][nd][now];
    if (ret != -1) return ret;

    ret = 500;
    if (a[st] == a[nd]) {
        ret = now + solve(st + 1, nd - 1, 0);
        for (int i = st + 1; i <= nd - 2; i++) {
            ret = min(ret, now + solve(st + 1, i, 1) + solve(i + 1, nd - 1, 0));
            ret = min(ret, now + solve(st + 1, i, 0) + solve(i + 1, nd - 1, 1));
        }
    }

    for (int i = st; i <= nd - 1; i++) {
        ret = min(ret, solve(st, i, 1) + solve(i + 1, nd, 1));
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        mem(dp, -1);
        cout << solve(0, n-1, 1) << endl;
    }

    return 0;
}





