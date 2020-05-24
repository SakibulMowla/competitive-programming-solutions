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

struct edge {
    int weight, type, indx;
    edge () {}
    edge (int a, int b, int c) {
        weight = a, type = b, indx = c;
    }
    bool operator < (const edge& x) const {
        return (x.weight == weight) ? (x.type < type) : (weight < x.weight);
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].weight >> edges[i].type;
        edges[i].indx = i;
    }

    sort(edges.begin(), edges.end());

//    for (int i = 0; i < m; i++) {
//        cout << ">> " << edges[i].weight << ' ' << edges[i].type << ' ' << edges[i].indx << endl;
//    }

    vector <pii> ans(m);
    stack <pii> reserve;
    bool flag = true;
    int need = m - n + 1, got = 0;
    int now = 1;

    for (int i = 0; i < m; i++) {
        if (edges[i].type == 0) {
            if (sz(reserve) == 0) {
                flag = false;
                break;
            } else {
                ans[edges[i].indx] = reserve.top();
                reserve.pop();
            }
        } else {
            ans[edges[i].indx] = {now, now + 1};
            now++;
//            cout << ">> " << i << ' ' << now << endl;
            for (int i = now - 2; i >= 1 && got < need; i--) {
                reserve.push({i, now});
                got++;
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

    return 0;
}





