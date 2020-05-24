#include <bits/stdc++.h>

using namespace  std;

namespace matching {
    typedef int val_t;
    const int SIZE = 500 + 2;
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

int num[502][2];
char type[502][2];

int main() {
    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int c, d, v;
        scanf("%d %d %d", &c, &d, &v);

        for (int i = 1; i <= v; i++) {
            scanf(" %c%d %c%d", &type[i][0], &num[i][0], &type[i][1], &num[i][1]);
        }

        matching::v1 = v;

        for (int i = 0; i < v; i++)
            matching::graph[i].clear();

        for (int i = 1; i <= v; i++) {
            for (int j = i + 1; j <= v; j++) {
                if ((type[i][0] == type[j][1] && num[i][0] == num[j][1]) ||
                    (type[j][0] == type[i][1] && num[j][0] == num[i][1])) {
                    matching::graph[i - 1].push_back(j - 1);
                    matching::graph[j - 1].push_back(i - 1);
                }
            }
        }

        printf("%d\n", v - matching::hopcroft() / 2);
    }
    return 0;
}

