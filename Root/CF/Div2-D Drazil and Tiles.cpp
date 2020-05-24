#include <bits/stdc++.h>

using namespace  std;

#define SZ 2002

int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

char s[SZ][SZ];
int deg[SZ][SZ];

inline void addEdge (int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        if (y1 > y2) swap(y1, y2);
        s[x1][y1] = '<';
        s[x2][y2] = '>';
    }
    if (y1 == y2) {
        if (x1 > x2) swap(x1, x2);
        s[x1][y1] = '^';
        s[x2][y2] = 'v';
    }
    return;
}

int n, m;

inline bool ok (int u, int v) {
    return (u>=0 && u<n && v>=0 && v<m);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    queue < pair <int, int> > Q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                int cnt = 0;
                for (int k = 0; k < 4; k++){
                    int u = i + x[k];
                    int v = j + y[k];
                    if (ok(u, v) && s[u][v] == '.') {
                        cnt++;
                    }
                }
                deg[i][j] = cnt;
                if (cnt == 1) Q.push({i, j});
            }
        }
    }


    while (!Q.empty()) {
        auto a = Q.front().first;
        auto b = Q.front().second;
        Q.pop();
        if (s[a][b] != '.') continue;

        for (int i = 0; i < 4; i++) {
            int u = a + x[i];
            int v = b + y[i];
            if (ok(u, v) && s[u][v] == '.') {
                addEdge(a, b, u, v);
                for (int j = 0; j < 4; j++) {
                    int c = u + x[j];
                    int d = v + y[j];
                    if (ok(c, d) && s[c][d] == '.') {
                        deg[c][d]--;
                        if (deg[c][d] == 1) {
                            Q.push({c, d});
                        }
                    }
                }
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                printf("Not unique\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }

    return 0;
}






