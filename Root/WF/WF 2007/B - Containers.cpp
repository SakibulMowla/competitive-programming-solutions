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

#define SZ 30

namespace matching {
    typedef int val_t;
    const int SIZE = 1010;
    int v1, v2;
    vector<int> graph[SIZE];
    int mx[SIZE], my[SIZE];
    int total_matching;
    int dist[SIZE];
    int inf_dist;

    bool bfs() {
        int x, y;
        queue<int> q;
        for (x = 0 ; x < v1 ; x++) {
            if (mx[x] == -1) {
                dist[x] = 0;
                q.push(x);
            } else
                dist[x] = -1;
        }
        bool flg = false;
        while (!q.empty()) {
            x = q.front();
            q.pop();
            for (int i = 0 ; i < graph[x].size() ; i++) {
                y = graph[x][i];
                if (my[y] == -1) {
                    inf_dist = dist[x] + 1;
                    flg = true;
                } else if (dist[my[y]] == -1) {
                    dist[my[y]] = dist[x] + 1;
                    q.push(my[y]);
                }
            }
        }
        return flg;
    }

    bool dfs(int x) {
        if (x == -1) return true;
        for (int i = 0 ; i < graph[x].size() ; i++) {
            int y = graph[x][i];
            int tmp = (my[y] == -1) ? inf_dist : dist[my[y]];
            if (tmp == dist[x] + 1 && dfs(my[y])) {
                mx[x] = y;
                my[y] = x;
                return true;
            }
        }
        dist[x] = -1;
        return false;
    }

    int hopcroft() {
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
        total_matching = 0;
        while (bfs()) {
            for (int x = 0 ; x < v1 ; x++)
                if (mx[x] == -1 && dfs(x))
                    total_matching++;
        }
        return total_matching;
    }
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    int Test = 0;
    string s;

    while (cin >> s) {
        if (s == "end") break;

        for (int i = 0; i < sz(s); i++) {
            clr(matching::graph[i]);
        }
        matching::v1 = matching::v2 = sz(s);

        for (int i = 0; i < sz(s); i++) {
            for (int j = i + 1; j < sz(s); j++) {
                if (s[i] >= s[j]) {
                    matching::graph[i].pb(j);
                }
            }
        }

        cout << "Case " << ++Test << ": " << sz(s) - matching::hopcroft() << '\n';
    }



    return 0;
}






