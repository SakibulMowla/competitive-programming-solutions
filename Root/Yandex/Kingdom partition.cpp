
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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Solve {
    int n, m, k;
    vector <pii> life;
    vector <pii> magic;
    vector < vector <char> > grid;
    vector < queue <pii> > kingdom;

    Solve (int n, int m, int k): n(n), m(m), k(k), life(k), magic(k), grid(n, vector <char> (m, '.')), kingdom(k) {
        for (auto &x: life) cin >> x.X >> x.Y;
        for (auto &x: magic) cin >> x.X >> x.Y;

        sort(life.begin(), life.end());
        sort(magic.begin(), magic.end());

        for (int i = 0; i < k; i++) {
            grid[life[i].X][life[i].Y] = i + 'a';
        }

        for (int i = 0; i < k; i++) {
            bfs(i);
        }

        populate();

        for (auto &x: grid) {
            for (auto &y: x) {
                cout << y;
            }
            cout <<endl;
        }
    }

    void bfs (int indx) {
        vector < vector <pii> > par(n, vector <pii> (m, {0, 0}));
        vector < vector <bool> > vis(n, vector <bool> (m, false));
        queue <pii> q;
        q.push(life[indx]);
        vis[life[indx].X][life[indx].Y] = true;

        while (!q.empty()) {
            pii u = q.front(); q.pop();
            if (u == magic[indx]) break;
            for (int i = 0; i < 4; i++) {
                int nx = u.X + dx[i];
                int ny = u.Y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == '.') {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                    par[nx][ny] = u;
                }
            }
        }

        pii u = magic[indx];
        int len = 0;
        while (u != life[indx] && len <= 3000) {
            grid[u.X][u.Y] = indx + 'a';
            kingdom[indx].push(u);
            u = par[u.X][u.Y];
            len++;
        }
        kingdom[indx].push(life[indx]);

        return;
    }

//    void populate() {
//        while (sz(kingdom) != 0) {
//            int now = rand() % sz(kingdom);
//            while (!kingdom[now].empty()) {
//                pii u = kingdom[now].front(); kingdom[now].pop();
//                bool flag = false;
//                for (int i = 0; i < 4; i++) {
//                    int nx = u.X + dx[i];
//                    int ny = u.Y + dy[i];
//                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
//                        grid[nx][ny] = (char)(info[now].X + 'a');
//                        kingdom[now].push({nx, ny});
//                        flag = true;
//                        break;
//                    }
//                }
//                if (flag == true) {
//                    break;
//                }
//            }
//            if (sz(kingdom[now]) == 0) {
//                kingdom.erase(kingdom.begin() + now);
//                info.erase(info.begin() + now);
//            }
//        }
//        return;
//    }


    void populate() {
        for (int now = 0; now < k; now++) {
            while (!kingdom[now].empty()) {
                pii u = kingdom[now].front(); kingdom[now].pop();
                for (int i = 0; i < 4; i++) {
                    int nx = u.X + dx[i];
                    int ny = u.Y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                        grid[nx][ny] = (char)(now + 'a');
                        kingdom[now].push({nx, ny});
                    }
                }
            }
        }
        return;
    }
};

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    Solve sol(n, m, k);

    return 0;
}




