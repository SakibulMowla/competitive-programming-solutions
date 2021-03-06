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

    int n;
    cin >> n;

    bool change = false;
    vector <pii> a(n);
    for (auto &x: a) cin >> x.X >> x.Y, change = (change || (x.X != x.Y));

    if (change) cout << "rated" << endl;
    else {
        int seq = 1;
        for (int i = 1; i < n; i++) {
            if (a[i].X > a[i - 1].X) {
                seq = 0;
                break;
            }
        }
        cout << (seq ? "maybe" : "unrated") << endl;
    }

    return 0;
}





