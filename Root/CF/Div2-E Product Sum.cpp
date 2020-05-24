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


#define SZ 200010

ll M[SZ], C[SZ]; //y=mx+c we need only m(slope) and c(constant)

bool bad (int l1, int l2, int l3) { // prev, cur, next
    return (C[l3]-C[l1]) * (M[l1]-M[l2]) >= (C[l2]-C[l1]) * (M[l1]-M[l3]);
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
	return;
}


ll bs (ll x, int last) {
	int l = -1, r = last - 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (M[m] * x + C[m] <= M[m + 1] * x + C[m + 1])
			l = m;
		else
			r = m;
	}
	return M[r] * x + C[r];
}


int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <ll> a(n + 1), sum(n + 1, 0);
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += i * a[i];
        sum[i] = sum[i-1] + a[i];
    }

    ll del = 0;
    int  last = 0;

    for (ll i = 1; i <= n; i++) {
        if (i > 1) del = max(del, bs(a[i], last) + sum[i-1] - i * a[i]);
        add(i, -sum[i-1], last);
    }

    last = 0;

    for (ll i = n; i >= 1; i--) {
        if (i < n) del = max(del, bs(-a[i], last) + sum[i] - i * a[i]);
        add(-i, -sum[i], last);
    }

    cout << ans + del << endl;

    return 0;
}
