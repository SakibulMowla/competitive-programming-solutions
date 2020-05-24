#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 500010

ll a[SZ];
ll b[SZ];
ll d[SZ];
ll e[SZ];

inline bool c (char i) {
    return i == 'I' || i == 'E' || i == 'A' || i == 'O' || i == 'U' || i == 'Y';
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    FAST

    string s;
    cin >> s;

    int n = sz(s);

    for (int i = 0; i < n; i++) {
        if (!c(s[i])) {
            continue;
        }

        int l = i + 1;
        int r = n - i;
        int m = min(l, r);

        a[1]++;
        a[m+1]--;

        if (l > r) swap(l, r);

        if (l != r) {
            b[l+1] += (ll)m;
            b[r+1] -= (ll)m;
        }

        e[r+2]--;
        e[l+r]++;
        d[r+1] += (ll)(m-1);
    }

    for (int i = 1; i <= n; i++) {
        a[i] += a[i-1];
        b[i] += b[i-1];
        e[i] += e[i-1];
        d[i] += d[i-1] + e[i];
    }

    for (int i = 1; i <= n; i++) {
        a[i] *= (ll)i;
    }

    double ans = 0.0;
    for (int i = 1; i <= n; i++) {
        ans += (double)(a[i] + b[i] + d[i]) / (double)i;
    }

    cout << fixed << setprecision(12) << ans << '\n';


    return 0;
}






