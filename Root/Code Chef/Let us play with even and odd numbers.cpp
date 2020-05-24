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
const ll mod = 1LL;

#define SZ 100010



int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll e, o;
        cin >> e >> o;
        if ((e + o) % 5 != 0) {
            cout << -1 << '\n';
        } else {
            if (e > ((e + o) * 2 / 5)) {
                cout << e - ((e + o) * 2 / 5) << '\n';
            } else {
                cout << o - ((e + o) * 3 / 5) << '\n';
            }
        }
    }

    return 0;
}






