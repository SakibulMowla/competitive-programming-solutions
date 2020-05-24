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
const ll mod = 1E9 + 7;


#define SZ 100010

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    vector <ll> two(SZ, 1);
    for (int i = 1; i <= 100000; i++) {
        two[i] = (two[i - 1] << 1);
        if (two[i] >= mod) two[i] -= mod;
    }

    int n;
    cin >> n;

    vector <int> a(n), cnt(SZ, 0), dp(SZ, 0);

    for (auto &x: a) cin >> x, cnt[x]++;

    for (int i = 100000; i >= 1; i--) {
        int multiples = cnt[i];
        for (int j = i + i; j <= 100000; j += i) {
            multiples += cnt[j];
            dp[i] -= dp[j];
            if (dp[i] < 0) dp[i] += mod;
        }
        dp[i] += two[multiples] - 1;
        if (dp[i] >= mod) dp[i] -= mod;
    }

    cout << dp[1] << endl;

    return 0;
}





