#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
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

#define SZ  200010

char s[2][SZ];
int xx[] = {0, -1, -1, 1, 1};
int yy[] = {1, 0, 1, 0, 1};
int dd[] = {0, 1, 1, 1, 1};
int n;

struct data {
    int x, y, d;
    data () {}
    data (int _x, int _y, int _d) {
        x = _x, y = _y, d = _d;
    }
    bool operator < (const data &x) const {
        return d > x.d;
    }
};

int dist[2][SZ];

int bfs (int a, int b) {
    priority_queue <data> pq;
    if (s[a][b] == '.') {
        pq.push(data(a, b, 0));
        dist[a][b] = 0;
    }
    while (!pq.empty()) {
        data u = pq.top(); pq.pop();
        for (int i = 0; i < 5; i++) {
            int p = u.x + xx[i];
            int q = u.y + yy[i];
            if (p >= 0 && p <= 1 && q >= 0 && q <= n-1 && s[p][q] == '.' && dist[p][q] > dist[u.x][u.y] + dd[i]) {
                dist[p][q] = dist[u.x][u.y] + dd[i];
                pq.push(data(p, q, dist[p][q]));
            }
        }
    }
    return min(dist[0][n-1], dist[1][n-1]);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%s %s", s[0], s[1]);
        n = strlen(s[0]);
        for (int i = 0; i < n; i++) {
            dist[0][i] = dist[1][i] = inf;
        }
        int ans = min(bfs(0, 0), bfs(1, 0));
        if (ans == inf) printf("No\n");
        else printf("Yes\n%d\n", ans);
    }

    return 0;
}





