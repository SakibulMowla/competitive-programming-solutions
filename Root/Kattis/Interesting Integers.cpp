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

vector <ll> F;

struct Solve {
    ll n;

    Solve (ll n): n(n) {
//        naive();
        better();
    }

    void naive () {
        for (int j = 1; ; j++) {
            for (int i = 1; i <= j; i++) {
                ll a = i, b = j, c = i + j;
                while (c <= n) {
                    if (c == n) {
                        cout << i << ' ' << j << endl;
                        return;
                    }
                    c = a + b;
                    a = b;
                    b = c;
                }
            }
        }
    }

    void better () {
        for (ll b = 1; ; b++) {
            for (int k = 1; k <= 50; k++) {
                ll lft = n - b * F[k-1];
                if (lft < 0) {
                    break;
                }
                if (lft > 0 && lft % F[k-2] == 0) {
                    ll a = lft / F[k-2];
                    if (a <= b) {
                        cout << a << ' ' << b << endl;
                        return;
                    }
                }
            }
        }
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    F.pb(1);
    F.pb(1);
    for (int i = 2; i <= 50; i++) {
        F.pb(F[i - 1] + F[i - 2]);
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll n;
        cin >> n;
        Solve Task(n);
    }

    return 0;
}



