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

#define SZ (1<<15)+10


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int a[SZ];
    vector <pii> v;
    stack <pii> stk;
    vector <int> ans[SZ];

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < (1<<n); i++) {
            cin >> a[i+1];
            stk.push({a[i+1], i+1});
            clr(ans[i+1]);
        }

        while (sz(stk) != 1) {
            clr(v);
            while (!stk.empty()) {
                pii p = stk.top(); stk.pop();
                pii q = stk.top(); stk.pop();
                if (p.X > q.X) {
                    v.pb({min(p.X-q.X+k, a[p.Y]), p.Y});
                    ans[p.Y].pb(q.Y);
                } else if (p.X < q.X) {
                    v.pb({min(q.X-p.X+k, a[q.Y]), q.Y});
                    ans[q.Y].pb(p.Y);
                } else if (p.Y < q.Y) {
                    v.pb({min(p.X-q.X+k, a[p.Y]), p.Y});
                    ans[p.Y].pb(q.Y);
                } else {
                    v.pb({min(q.X-p.X+k, a[q.Y]), q.Y});
                    ans[q.Y].pb(p.Y);
                }
            }
            for (int i = 0; i < sz(v); i++) {
                stk.push(v[i]);
            }
        }

        cout << stk.top().Y << '\n';
        for (int i = 0; i < sz(ans[stk.top().Y]); i++) {
            if (i) cout << ' ';
            cout << ans[stk.top().Y][i];
        }
        cout << '\n';

        stk.pop();
    }

    return 0;
}







