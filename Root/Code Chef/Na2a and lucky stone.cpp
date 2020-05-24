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

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll n;
        cin >> n;

        ll m = n;
        int cnt = 0;

        while (m % 5 == 0) {
            m /= 5;
            cnt++;
        }

        m = n;
        while (m % 2 == 0) {
            m /= 2;
            cnt--;
        }

        cnt = cnt / 2 + cnt % 2;

        for (int i = 0; i < cnt; i++) {
            n *= 4LL;
        }

        cout << n << endl;
    }


    return 0;
}







