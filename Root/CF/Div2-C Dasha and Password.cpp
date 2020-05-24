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


#define SZ 10010

int categorize (char c) {
    if (c >= 'a' && c <= 'z') return 0;
    if (c >= '0' && c <= '9') return 1;
    return 2;
}

int dp[SZ][10];

int solve (int n, int mask, vector < vector <int> >& cost) {
    if (n == -1) {
        if (mask == 0) return 0;
        return 5000;
    } else {
        int &ret = dp[n][mask];
        if (ret != -1) return ret;

        ret = solve(n - 1, mask, cost);
        for (int i = 0; i < 3; i++) {
            if (mask & (1<<i)) {
                ret = min(ret, cost[n][i] + solve(n - 1, mask & ~(1<<i), cost));
            }
        }

        return ret;
    }
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector < vector <int> > cost(n, vector <int> (3, 5000));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            cost[i][categorize(s[j])] = min(cost[i][categorize(s[j])], j);
        }
        for (int j = m - 1, k = 1; j >= 0; j--, k++) {
            cost[i][categorize(s[j])] = min(cost[i][categorize(s[j])], k);
        }

//        cout << ">> " << cost[i][0] << ' ' << cost[i][1] << ' ' << cost[i][2] << endl;
    }

    mem(dp, -1);
    cout << solve(n - 1, (1<< 3) - 1, cost) << endl;

    return 0;
}





