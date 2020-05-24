#include <bits/stdc++.h>

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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        stack <pii> stk;
        for (int i = 0; i < n; i++) {
            pii a;
            cin >> a.X;
            a.Y = a.X;
            while (!stk.empty()) {
                pii u = stk.top();
                if (u.Y + 1 == a.X || a.Y + 1 == u.X) {
                    stk.pop();
                    a.X = min(a.X, u.X);
                    a.Y = max(a.Y, u.Y);
                } else {
                    break;
                }
            }
            stk.push(a);
        }
        if (sz(stk) == 1) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
