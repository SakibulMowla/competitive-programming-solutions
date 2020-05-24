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

    int n, k;
    cin >> n >> k;

    int mx = (n / 2 + n % 2) * (n / 2 + n % 2) + (n / 2) * (n / 2);

    if (k > mx) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                for (int j = 0; j < n; j++) {
                    if ((j & 1) && k) {
                        k--;
                        cout << 'L';
                    } else {
                        cout << 'S';
                    }
                }
            } else {
                for (int j = 0; j < n; j++) {
                    if (!(j & 1) && k) {
                        k--;
                        cout << 'L';
                    } else {
                        cout << 'S';
                    }
                }
            }
            cout << endl;
        }
    }


    return 0;
}







