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

#define SZ 10010

struct data {
    int idx;
    ll val;
};

data arr[SZ];
ll dp[SZ];
int path[SZ];

bool comp (data a, data b) {
    if (a.val == b.val) {
        return a.idx < b.idx;
    }
    return a.val < b.val;
}

int main() {
//    #if defined JESI
        freopen("iq.in", "r", stdin);
        freopen("iq.out", "w", stdout);
//    #endif

    ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].val;
            arr[i].idx = i;
        }

        sort(arr + 1, arr + n + 1, comp);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = numeric_limits <ll> :: max();
            for (int j = 1; j <= i; j++) {
                if (dp[i] > (n - j + 1) * arr[i].val + dp[j - 1]) {
                    dp[i] = (n - j + 1) * arr[i].val + dp[j - 1];
                    path[i] = j;
                }
            }
        }

        cout << dp[n] << endl;

        vector < vector <int> > ans;
        int idx = 0;

        for (int i = n; i; i = path[i] - 1) {
            ans.pb(vector<int>());
            for (int j = i; j >= path[i]; j--) {
                ans[idx].pb(arr[j].idx);
            }
            idx++;
        }

        cout << idx << endl;

        for (int i = idx - 1; i >= 0; i--) {
            cout << sz(ans[i]);
            for (int j = 0; j < sz(ans[i]); j++) {
                cout << ' ' << ans[i][j];
            }
            cout << endl;
        }
    }


    return 0;
}






