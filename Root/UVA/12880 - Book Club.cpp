#include <bits/stdc++.h>

using namespace  std;

namespace matching {
    typedef int val_t;
    const int SIZE = 20000 + 2;
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
} // namespace matching

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}

int main() {
    int n, m;
    while (scanf("%d", &n) == 1) {
        inp(m);
        matching::v1 = n;

        for (int i = 0; i < n; i++)
            matching::graph[i].clear();

        for (int i = 0; i < m; i++) {
            int u, v;
            inp(u); inp(v);
            matching::graph[u].push_back(v + n);
        }

        printf("%s\n", matching::hopcroft() == n? "YES": "NO");
    }
    return 0;
}

