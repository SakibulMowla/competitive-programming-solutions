#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007;

#define SZ  100010


ll maxSubArraySum (vector <ll>& a, int n) {
    ll max_so_far = -10e17, max_ending_here = 0;

    for (int i = 0; i < n; i++) {
        if (i & 1) max_ending_here = max_ending_here - a[i];
        else max_ending_here = max_ending_here + a[i];

        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <ll> a(n), x(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) x[i - 1] = abs(a[i] - a[i - 1]);
    }

    ll ans = maxSubArraySum(x, n - 1);
    if (n > 2) {
        x.erase(x.begin());
        ans = max(ans, maxSubArraySum(x, n - 2));
    }

    cout << ans << endl;

    return 0;
}




