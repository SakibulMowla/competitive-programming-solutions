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

int SOD (int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
//    #if defined JESI
        freopen("digits.in", "r", stdin);
        freopen("digits.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    vector <int> cnt(55, 0);
    vector < vector <ll> > sum(55);

    for (int i = 1; i <= 100000; i++) {
        int sod = SOD(i);
        cnt[sod]++;
        sum[sod].pb(i);
    }

    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j < cnt[i]; j++) {
            sum[i][j] += sum[i][j-1];
        }
    }

    int n;
    cin >> n;

    ll ans = 1E17;
    for (int i = 1; i <= 50; i++) {
        if (cnt[i] >= n) {
            ans = min(ans, sum[i][n - 1]);
        }
    }

    cout << ans << endl;

    return 0;
}





