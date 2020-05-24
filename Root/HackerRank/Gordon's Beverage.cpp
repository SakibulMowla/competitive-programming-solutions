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

#define SZ 400010

struct data {
    int x, y, z, t, c, idx;
    data () {}
    data (int _x, int _y, int _z, int _t, int _c, int _idx) {
        x = _x, y = _y, z = _z, t = _t, c = _c, idx = _idx;
    }
};

bool comp (data p, data q) {
    if (p.x == q.x) {
        if (p.y == q.y) {
            if (p.z == q.z) {
                if (p.c == q.c) {
                    if (p.c == 1) {
                        return p.t > q.t;
                    } else {
                        return p.t < q.t;
                    }
                } else {
                    return p.c < q.c;
                }
            } else {
                return p.z < q.z;
            }
        } else {
            return p.y < q.y;
        }
    } else {
        return p.x < q.x;
    }
}

data a[SZ];
int sum[SZ];
int ans[SZ];

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = data(x, y, z, 1, 2, 0);
        a[n + i] = a[i];
        a[n + i].x -= 4;
        a[n + i].y -= 4;
        a[n + i].z -= 4;
        a[n + i].t = 1;
        a[n + i].c = 1;
    }

    int m;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a[n+n+i].x >> a[n+n+i].y >> a[n+n+i].z >> a[n+n+m+i].x >> a[n+n+m+i].y >> a[n+n+m+i].z;
        a[n+n+i].t = 2;
        a[n+n+i].c = 1;
        a[n+n+m+i].t = 2;
        a[n+n+m+i].c = 2;
        a[n+n+m+i].idx = i;
    }

    sort(a + 1, a + n + n + m + m + 1, comp);

    for (int i = 1; i <= n + n + m + m; i++) {
        if (a[i].t == 1) {
            if (a[i].c == 1) {

            } else {

            }
        } else {
            if (a[i].c == 1) {

            } else {

            }
        }
        sum[i] += sum[i-1];
    }

    for (int i = 0; i <= m; i++) {
        cout << ans[i] << endl;
    }


    return 0;
}







