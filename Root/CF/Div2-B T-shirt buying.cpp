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
    int p, a, b, id;
    data () {}
    data (int p, int a, int b, int id): p(p), a(a), b(b), id(id) {}
};

bool comp (data x, data y) {
    return x.p < y.p;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <data> shirt(n);

    for (int i = 0; i < n; i++) cin >> shirt[i].p;
    for (int i = 0; i < n; i++) cin >> shirt[i].a;
    for (int i = 0; i < n; i++) cin >> shirt[i].b;
    for (int i = 0; i < n; i++) shirt[i].id = i;

    sort(shirt.begin(), shirt.end(), comp);

    vector < queue <pii> > vq(4);
    for (int i = 0; i < n; i++) {
        vq[shirt[i].a].push({shirt[i].id, shirt[i].p});
        vq[shirt[i].b].push({shirt[i].id, shirt[i].p});
    }

    set <int> ms;

    int m;
    cin >> m;
    while (m--) {
        int type;
        cin >> type;

        int ans = -1;
        while (!vq[type].empty()) {
            pii u = vq[type].front(); vq[type].pop();
            if (ms.find(u.X) == ms.end()) {
                ms.insert(u.X);
                ans = u.Y;
                break;
            }
        }

        cout << ans << ' ';
    }
    cout << endl;

    return 0;
}





