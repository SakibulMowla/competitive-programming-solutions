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
    while (cin >> n) {
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                if (ans == 0) ans = 1;
                int j = i + 1;
                while (j < n && a[j] == 0) {
                    j++;
                }
                if (j < n && a[j] == 1) {
                    ans *= (ll)(j - i);
                }
                i = j - 1;
            }
        }
        cout << ans << endl;
    }


    return 0;
}





