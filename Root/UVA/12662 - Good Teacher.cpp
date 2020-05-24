#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

string a[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int pos;
        cin >> pos;

        if (a[pos] != "?") {
            cout << a[pos] << '\n';
        } else {
            int lp = -200, rp = 200;
            for (int i = pos - 1; i >= 1; i--) {
                if (a[i] != "?") {
                    lp = i;
                    break;
                }
            }
            for (int i = pos + 1; i <= n; i++) {
                if (a[i] != "?") {
                    rp = i;
                    break;
                }
            }
            if (pos - lp == rp - pos) {
                cout << "middle of " << a[lp] << " and " << a[rp] << '\n';
            } else if (pos - lp < rp - pos) {
                int k = pos - lp;
                while (k--){
                    cout << "right of ";
                }
                cout << a[lp] << '\n';
            } else {
                int k = rp - pos;
                while (k--) {
                    cout << "left of ";
                }
                cout << a[rp] << '\n';
            }
        }
    }

    return 0;
}




