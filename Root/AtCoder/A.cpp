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

    ll Q, H, S, D, n;
    cin >> Q >> H >> S >> D >> n;

    Q *= 8;
    H *= 4;
    S *= 2;

    ll mn = min(min(Q, H), min(S, D));
    ll ans = 0;

    if (Q == mn) {
//        cout << "Q" << endl;
        ans = Q * (n / 2) + (Q / 2) * (n & 1);
    } else if (H == mn) {
//        cout << "H" << endl;
        ans = H * (n / 2) + (H / 2) * (n & 1);
    } else if (S == mn) {
//        cout << "S" << endl;
        ans = S * (n / 2) + (S / 2) * (n & 1);
    } else {
//        cout << "D" << endl;
        ans = D * (n / 2);
        if (n & 1) {
            mn = min(Q, min(H, S));
            ans += mn / 2;
        }
    }

    cout << ans << endl;

    return 0;
}




