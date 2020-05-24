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
const ll mod = (1E9)+7;


#define SZ 100010

int dp[201][201][1001];
int a[205];
int N, K;

ll solve (int indx, int open, int k) {
    if (indx) k += (a[indx] - a[indx-1]) * open;
    if (open < 0 || k > K) return 0;
    if (indx == N) return open == 0;

    if (dp[indx][open][k] != -1) return dp[indx][open][k];

    ll ret = solve(indx + 1, open + 1, k);
    ret += solve(indx + 1, open - 1, k) * open;
    ret += solve(indx + 1, open, k) * open;
    ret += solve(indx + 1, open, k);
    ret %= mod;

    return dp[indx][open][k] = ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    while (cin >> N >> K) {
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a + N);
        mem(dp, -1);
        cout << solve(0, 0, 0) << endl;
    }

    return 0;
}





