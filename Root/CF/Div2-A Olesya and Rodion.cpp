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

int dp[110][12][2];
int n, k;

int solve (int pos, int md, int strt) {
    if (pos == 0) return (md == 0);
    int &ret = dp[pos][md][strt];
    if (ret != -1) return ret;

    int beg = 0 + strt;
    ret = 0;

    for (int i = beg; i < 10; i++) {
        ret = max(ret, solve(pos - 1, ((md * 10) + i)%k, 0));
    }

    return ret;
}

void path(int pos, int md, int strt) {
    if (pos == 0) return;
    int beg = 0 + strt;
    for (int i = beg; i < 10; i++) {
        if (solve(pos - 1, ((md * 10) + i)%k, 0)) {
            cout << i;
            return path(pos - 1, ((md * 10) + i)%k, 0);
        }
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    cin >> n >> k;
    mem(dp, -1);
    if (!solve(n, 0, 1)) cout << -1 << endl;
    else {
        path(n, 0, 1);
        cout << endl;
    }

    return 0;
}


