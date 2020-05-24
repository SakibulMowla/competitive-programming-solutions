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

    ll n, k;
    cin >> n >> k;

    ll m = n, two = 0, five = 0;
    while (m > 0 && m % 2 == 0) {
        two++;
        m /= 2;
    }
    while (m > 0 && m % 5 == 0) {
        five++;
        m /= 5;
    }
    while (five < k) {
        five++;
        n *= 5;
    }
    while (two < k) {
        two++;
        n *= 2;
    }

    cout << n << endl;

    return 0;
}





