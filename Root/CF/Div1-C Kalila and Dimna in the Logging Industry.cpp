#include <bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

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

ll M[SZ], C[SZ]; //y=mx+c we need only m(slope) and c(constant)

bool bad (int l1, int l2, int l3) {
    return 1.0 * (C[l3]-C[l1]) * (M[l1]-M[l2]) <= 1.0 * (C[l2]-C[l1]) * (M[l1]-M[l3]);
//query x values is non-decreasing (reverse(> sign) for vice verse)
}

//Adding should be done serially. If we want minimum y coordinate(value) then
//maximum valued m should be inserted first and if we want maximum y
//coordinate(value) then minimum valued m should be inserted first
void add (ll m, ll c, int &last) {
    M[last] = m;
    C[last++] = c;
    while (last >= 3 && bad(last-3, last-2, last-1)) {
        M[last-2] = M[last-1];
        C[last-2] = C[last-1];
        last--;
    }
}

//Returns the minimum y-coordinate of any intersection between a given vertical
//This can only be applied if the query of vertical line(x) is already sorted
long long query (ll x, int &pointer, int last) {
    if (pointer >= last) pointer = last - 1;
    //non-decreasing
    while (pointer < last - 1 && M[pointer+1] * x + C[pointer+1] <= M[pointer] * x + C[pointer]) // Min Value wanted... (reverse(> sign) for max value)
        pointer++;
    return M[pointer] * x + C[pointer];
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <ll> a(n + 1), b(n + 1), sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = a[i] + sum[i-1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    /* n^2 DP Solution
    vector <ll> dp(n + 1, numeric_limits<ll>::max());
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            dp[i] = min(dp[i], dp[j] + b[j] * a[i]);
        }
    }
    */

    int pointer = 0, last = 0;
    ll ans;
    add(b[1], 0, last);
    for (int i = 1; i <= n; i++) {
        ans = query(a[i], pointer, last);
        if (i < n) add(b[i], ans, last);
    }

    cout << ans << endl;

    return 0;
}
