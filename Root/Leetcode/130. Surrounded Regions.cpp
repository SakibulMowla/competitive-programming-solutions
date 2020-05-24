int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        vector<vector<int>> dist(n, vector<int> (m, numeric_limits<int>::max()));
        queue<int> Q;

        for (int j = 0; j < m; j++) if (board[0][j] == 'O') dist[0][j] = 0, Q.push(0), Q.push(j);
        for (int j = 0; j < m; j++) if (board[n - 1][j] == 'O') dist[n - 1][j] = 0, Q.push(n - 1), Q.push(j);
        for (int i = 0; i < n; i++) if (board[i][0] == 'O') dist[i][0] = 0, Q.push(i), Q.push(0);
        for (int i = 0; i < n; i++) if (board[i][m - 1] == 'O') dist[i][m - 1] = 0, Q.push(i), Q.push(m - 1);
        
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            int v = Q.front(); Q.pop();
            for (int k = 0; k < 4; k++) {
                int nu = u + x[k];
                int nv = v + y[k];
                if (nu >= 0 && nu < n && nv >= 0 && nv < m && board[nu][nv] == 'O' && dist[nu][nv] > dist[u][v] + 1) {
                    dist[nu][nv] = dist[u][v] + 1;
                    Q.push(nu);
                    Q.push(nv);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && dist[i][j] == numeric_limits<int>::max()) {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};