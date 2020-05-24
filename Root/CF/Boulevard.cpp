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

struct data {
    int t, s, f, d;
};



int main() {
    #if defined JESIĵ
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <data> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].t >> a[i].s >> a[i].f;
        a[i].d = (a[i].f > a[i].s)? 1: -1;
    }

    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) if (i != j) {
            ans += Compare(a[i], a[j]);
        }
        if (i) cout << ' ';
        cout << ans;
    }
    cout << endl;

    return 0;
}


