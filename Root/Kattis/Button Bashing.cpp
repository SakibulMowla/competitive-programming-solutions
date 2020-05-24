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
const int inf = 1E7;
const ll mod = 1E9;

#define SZ 100010

struct Solve {
    vector <int> buttons;
    vector <int> dist;
    int n, target;

    Solve (int n, int target): n(n), target(target), buttons(n), dist(3601, inf) {
        for (auto &x: buttons) {
            cin >> x;
        }
        bfs();
        FindAns();
    }

    void bfs () {
        queue <int> Q;
        Q.push(0);
        dist[0] = 0;

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < n; i++) {
                int v = u + buttons[i];
                if (v > 3600) v = 3600;
                if (v < 0) v = 0;
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }

        return;
    }

    void FindAns () {
        for (int i = target; ; i++) {
            if (dist[i] != inf) {
                cout << dist[i] << ' ' << i - target << endl;
                return;
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

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, target;
        cin >> n >> target;
        Solve Task(n, target);
    }

    return 0;
}




