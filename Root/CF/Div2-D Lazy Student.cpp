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

struct data {
    int u, v, w;
    data () {}
    data (int a, int b, int c) {
        u = a, v = b, w = c;
    }
};

bool comp (data a, data b) {
    if (a.u == b.u) return a.v > b.v;
    return a.u < b.u;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        vector <data> info(m);
        int cnt = 0;
        for (auto &x: info) {
            cin >> x.u >> x.v;
            x.w = cnt++;
        }

        sort(info.begin(), info.end(), comp);
        stack <pii> stk;
        vector <pii> ans(m);

        int need = m - n + 1;
        cnt = 1;
        bool flag = true;

        for (int i = 0; i < m; i++) {
            if (info[i].v == 0) {
                if (sz(stk) == 0) {
                    flag = false;
                    break;
                } else {
                    ans[info[i].w] = stk.top();
                    stk.pop();
                }
            } else {
                ans[info[i].w] = {cnt, cnt + 1};
                ++cnt;
                for (int i = cnt - 2; i >= 1 && need; i--) {
                    need--;
                    stk.push({i, cnt});
                }
            }
        }

        if (!flag) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < m; i++) {
                cout << ans[i].X << ' ' << ans[i].Y << endl;
            }
        }
    }


    return 0;
}





