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
//    #if defined JESI
//        freopen("1.txt", "r", stdin);
        freopen("1.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int cnt = 0;
    for (int i = 0; i <= 1000; i++) {
        vector <int> v;
        int n = i;
        do {
            v.pb(n%10);
            n /= 10;
        } while (n);
        int lim = (1 << (sz(v))), sum = 0;
        for (int mask = 1; mask < lim; mask++) {
            int tmp = 1;
            for (int j = 0; j < sz(v); j++) {
                if (mask & (1<<j)) {
                    tmp *= v[j];
                }
            }
            sum += tmp;
        }
        if (sum % 2 == 0) cout << i << endl, cnt++;
    }
    cerr << cnt << endl;

    return 0;
}





