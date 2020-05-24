#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
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

    FAST

    int n;
    cin >> n;

    multiset <int> ms1, ms2, ms3;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms1.insert(x);
    }

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        ms2.insert(x);
    }

    for (int i = 0; i < n - 2; i++) {
        int x;
        cin >> x;
        ms3.insert(x);
    }

    for (auto it: ms2) {
        ms1.erase(ms1.find(it));
    }

    for (auto it: ms3) {
        ms2.erase(ms2.find(it));
    }

    cout << *ms1.begin() << '\n';
    cout << *ms2.begin() << '\n';

    return 0;
}







