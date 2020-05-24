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



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector <int> a(n), b(k);

    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    for (auto &x: a) {
        if (x == 0) {
            x = b[0];
            b.erase(b.begin());
        }
    }

    bool f = true;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            f = false;
            break;
        }
    }

    cout << (f ? "No" : "Yes") << endl;

    return 0;
}




