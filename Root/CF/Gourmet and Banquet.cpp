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

vector <pii> a[10000+1];

bool f (int n, int mid) {
    vector <int> need(n, mid);
    multiset <pii> ms;

    for (int i = 0; i <= 10000; i++) {
        for (int j = 0; j < sz(a[i]); j++) {
            ms.insert(a[i][j]);
        }
        while (ms.size() && ms.begin()->X < i) {
            ms.erase(ms.begin());
        }
        while (ms.size() && need[ms.begin()->Y] == 0) {
            ms.erase(ms.begin());
        }
        if (ms.size()) {
            need[ms.begin()->Y]--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (need[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);


    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        pii x;
        cin >> x.X >> x.Y;
        a[x.X].pb({x.Y - 1, i});
    }

    int lo = 1, hi = 10000;
    int ans = 0;

    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (f(n, mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << n * ans << endl;

    return 0;
}


