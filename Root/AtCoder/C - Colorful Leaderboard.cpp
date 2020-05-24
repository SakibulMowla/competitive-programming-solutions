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

    int mask = 0, free = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 1 && x <= 399) {
            mask |= (1 << 1);
        } else if (x >= 400 && x <= 799) {
            mask |= (1 << 2);
        } else if (x >= 800 && x <= 1199) {
            mask |= (1 << 3);
        } else if (x >= 1200 && x <= 1599) {
            mask |= (1 << 4);
        } else if (x >= 1600 && x <= 1999) {
            mask |= (1 << 5);
        } else if (x >= 2000 && x <= 2399) {
            mask |= (1 << 6);
        } else if (x >= 2400 && x <= 2799) {
            mask |= (1 << 7);
        } else if (x >= 2800 && x <= 3199) {
            mask |= (1 << 8);
        } else free++;
    }

    mask = __builtin_popcount(mask);

    int mn = (mask == 0? 1: mask);
    int mx = mask + free;

    cout << mn << ' ' << mx << endl;

    return 0;
}




