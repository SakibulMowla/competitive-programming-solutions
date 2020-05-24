#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;

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

    multiset <int> ms;

    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }

    vector <int> v;

    for (int i = 0; i < n; i++) {
        int now = *prev(ms.end());
        cout << now << ' ';
        ms.erase(prev(ms.end()));
        for (auto x: v) {
            ms.erase(ms.find(__gcd(x, now)));
            ms.erase(ms.find(__gcd(x, now)));
        }
        v.pb(now);
    }
    cout << endl;

    return 0;
}


