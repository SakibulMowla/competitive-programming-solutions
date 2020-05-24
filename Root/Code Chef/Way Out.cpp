#include <bits/stdc++.h>

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

#define SZ  1000010

int hole[SZ];
ll sum[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, h;
        cin >> n >> h;

        for (int i = 0; i <= n; i++) {
            hole[i] = 0;
            sum[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            hole[a + 1]++;
            hole[b + 2]--;
        }

        ll ans = (ll)n * (ll)h;

        for (int i = 1; i <= n; i++) {
            hole[i] += hole[i-1];
            sum[i] = sum[i-1] + (ll)hole[i];
            if (i >= h) {
                ans = min(ans, (ll)n * (ll)h - sum[i] + sum[i - h]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}





