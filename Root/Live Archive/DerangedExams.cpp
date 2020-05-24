#include "bits/stdc++.h"

using namespace std;

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
const ll mod = 1LL;

#define SZ  110

ll dp[(1<<17)+10];
ll fact[SZ];
int col[(1<<17)+10];
int now;

void pre () {
    fact[0] = 1LL;
    for (int i = 1; i < 18; i++) {
        fact[i] = (ll)i * fact[i-1];
//        cout << "> i = " << i << "fact[i] = " << fact[i] << '\n';
    }
}

int N, K;

ll solve (int mask, int cnt) {
    if (cnt == K) return 1LL;
    ll &ret = dp[mask];
    if (col[mask] == now) return ret;
    col[mask] = now;

    ret = 0LL;
    for (int i = 0; i < N; i++) {
        if (cnt != i && (mask & (1<<i))) {
            ret += solve(mask&~(1<<i), cnt+1);
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    pre();

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int kase, n, k;
        cin >> kase >> n >> k;

        now++;
        K = k;
        N = n;
        cout << kase << " " << fact[n-k] * solve((1<<n)-1, 0) << '\n';
    }


    return 0;
}




