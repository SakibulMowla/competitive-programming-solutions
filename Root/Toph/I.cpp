#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<int, pii>;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> G(n + 2, vector<char>(m + 2, '.'));
        vector<vector<int>> D(n + 2, vector<int>(m + 2, numeric_limits<int>::max()));

        pii start;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
            if (G[i][j] == '$') start = {i, j};
        }

        n += 2;
        m += 2;

        priority_queue<piii> pq;
        for (int j = 0; j < m; j++) {pq.push({0, {0, j}}); pq.push({0, {n - 1, j}}); D[0][j] = 0; D[n - 1][j] = 0;}
        for (int i = 0; i < n; i++) {pq.push({0, {i, 0}}), pq.push({0, {i, m - 1}}); D[i][0] = 0; D[i][m - 1] = 0;}

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            pii u = pq.top().second; pq.pop();
            for (int k = 0; k < 4; k++) {
                int nx = u.first + x[k];
                int ny = u.second + y[k];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if ((G[nx][ny] == '.' || G[nx][ny] == '$') && D[nx][ny] > D[u.first][u.second]) {
                        D[nx][ny] = D[u.first][u.second];
                        pq.push({-D[nx][ny], {nx, ny}});
                    } else if (G[nx][ny] == '*' && D[nx][ny] > D[u.first][u.second] + 1) {
                        D[nx][ny] = D[u.first][u.second] + 1;
                        pq.push({-D[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        int ans = D[start.first][start.second];
        cout << "Case " << cs + 1 << ": " << (ans == numeric_limits<int>::max()? "Impossible": to_string(ans)) << endl;
    }

    return 0;
}




