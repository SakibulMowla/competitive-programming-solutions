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

#define SZ 1000010

int cnt[SZ], dp[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, mx = 0, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        cnt[x]++;
        dp[x]++;
        if (dp[x] > ans) {
            ans = dp[x];
        }
    }

    for (int i = 1; i <= mx; i++) if (cnt[i]) {
        for (int j = i + i; j <= mx; j += i) if (cnt[j]) {
            dp[j] = max(dp[j], dp[i] + cnt[j]);
            if (dp[j] >= ans) {
                ans = dp[j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}





