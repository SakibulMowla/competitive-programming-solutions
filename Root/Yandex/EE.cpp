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

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    x1 += 200;
    y1 += 200;
    x2 += 200;
    y2 += 200;

    vector < vector < vector <int> > > dist(501, vector < vector <int> > (501, vector <int> (2, 1E9)));
    queue <int> q;
    q.push(x1);
    q.push(y1);
    q.push(1);
    q.push(x1);
    q.push(y1);
    q.push(0);
    dist[x1][y1][0] = 0;
    dist[x1][y1][1] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        int v = q.front(); q.pop();
        int dir = q.front(); q.pop();

        if (dir == 0) {
            for (int k = -1; k <= 1; k += 2) {
                int nu = u + k;
                int nv = v;
                if (nu >= 0 && nu <= 500 && nv >= 0 && nv <= 500 && dist[nu][nv][dir ^ 1] > dist[u][v][dir] + 1) {
                    dist[nu][nv][dir ^ 1] = dist[u][v][dir] + 1;
                    q.push(nu);
                    q.push(nv);
                    q.push(dir ^ 1);
                }
            }
        } else {
            for (int k = -1; k <= 1; k += 2) {
                int nu = u;
                int nv = v + k;
                if (nu >= 0 && nu <= 500 && nv >= 0 && nv <= 500 && dist[nu][nv][dir ^ 1] > dist[u][v][dir] + 1) {
                    dist[nu][nv][dir ^ 1] = dist[u][v][dir] + 1;
                    q.push(nu);
                    q.push(nv);
                    q.push(dir ^ 1);
                }
            }
        }
    }

    cout << min(dist[x2][y2][0], dist[x2][y2][1]) << endl;

    return 0;
}




