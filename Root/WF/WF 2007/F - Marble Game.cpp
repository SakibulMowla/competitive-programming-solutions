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
const ll mod = 1E9+7;

#define SZ 18
#define SZ1 65536+10

unordered_map <ll, int> dist;
pii hole[SZ];

int forbid[5][5][5][5];
int ishole[5][5];

ll seed;
ll seedP[SZ];

pii a[SZ];
pii t[SZ];

int Ccol[4][4];
int num[4][4];
int tcol[4][4];

int xx[] = {-1, 1, 0, 0}; ///U, D, L, R
int yy[] = {0, 0, -1, 1};

pii Move (int n, int nx, int ny, int k, int now, int tym) {
    tym = (tym && (k == 1));
//    if (tym) cout << tym << " func " << nx << ' ' << ny << '\n';
    if (ishole[nx][ny] != -1) return {nx, ny};
    while (1) {
        int tx = nx + xx[k];
        int ty = ny + yy[k];
//        if (tym) cout << "tx ty " << tx << ' ' << ty << '\n';
        if (tx < 0 || tx >= n || ty < 0 || ty >= n) break;
        if (forbid[nx][ny][tx][ty]) break;
        if (tcol[tx][ty] && ishole[tx][ty] != -1) {
            nx = tx;
            ny = ty;
//            if (tym) cout << ">>>>> 1\n";
            continue;
        }
        if (tcol[tx][ty]) {
//            if (tym) cout << ">>>>> 2\n";
            break;
        }
        if (ishole[tx][ty] != -1) {
//            cout << "Ishole " << tx << ' ' << ty << ' ' << ishole[tx][ty] << ' ' << now << '\n';
            if (ishole[tx][ty] == now) {
//                if (tym) cout << ">>>>> 3\n";
                return {tx, ty};
            } else {
//                if (tym) cout << ">>>>> 4\n";
                return {-1, -1};
            }
        }
        nx = tx;
        ny = ty;
    }
    return {nx, ny};
}

int bfs (int n, int m, queue <pii> &Q, ll now) {
    clr(dist);
    dist[now] = 0;

    queue <ll> tq;
    tq.push(now);

    while (!Q.empty()) {
        mem(Ccol, 0);

        for (int i = 0; i < m; i++) {
            a[i] = Q.front(); Q.pop();
            Ccol[a[i].X][a[i].Y] = 1;
            num[a[i].X][a[i].Y] = i;
//            cout << a[i].X << " " << a[i].Y << "   ";
        }

        int tym = 0;
        if (a[0].X == 0 && a[0].Y == 3 && a[1].X == 1 && a[1].Y == 1 && a[2].X == 3 && a[2].Y == 2) tym = 1;

//        cout << " Big Time = "  << tym << '\n';

        ll state = tq.front();
        tq.pop();

//        cout << "\n>> " << state << '\n';

//        if ()

        for (int i = 0; i < 4; i++) {
            for (int p = 0; p < 4; p++) {
                for (int q = 0; q < 4; q++) {
                    tcol[p][q] = Ccol[p][q];
                }
            }

            bool flag = 0;
            ll mask = 0;

            /*for (int j = 0; j < m; j++) {
                t[j] = Move(n, a[j].X, a[j].Y, i, j);
                if (t[j].X == -1) {
                    flag = 1;
                    break;
                }
                tcol[ a[j].X ][ a[j].Y ] = 0;
                tcol[ t[j].X ][ t[j].Y ] = 1;
                ll tmp = t[j].X * t[j].Y + t[j].Y;
                mask += tmp;
                mask *= seed;
            }*/

            if (i == 0) {
                for (int row = 0; row < n; row++) {
                    for (int col = 0; col < n; col++) {
                        if (Ccol[row][col]) {
//                            cout << "r c " << row << ' ' << col << '\n';
                            int j = num[row][col];
                            t[j] = Move(n, a[j].X, a[j].Y, i, j, 0);
//                            cout << "f f " << t[j].X << ' ' << t[j].Y << '\n';
                            if (t[j].X == -1) {
                                flag = 1;
                                break;
                            }
                            tcol[ a[j].X ][ a[j].Y ] = 0;
                            tcol[ t[j].X ][ t[j].Y ] = 1;
                            ll tmp = t[j].X * n + t[j].Y;
                            mask = (mask + (tmp * seedP[j]) % mod) % mod;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
            } else if (i == 1) {
                for (int row = n-1; row >= 0; row--) {
                    for (int col = 0; col < n; col++) {
                        if (Ccol[row][col]) {
//                            if (tym) cout << "r c " << row << ' ' << col << '\n';
                            int j = num[row][col];
                            t[j] = Move(n, a[j].X, a[j].Y, i, j, tym);
//                            if (tym) cout << "f f " << t[j].X << ' ' << t[j].Y << '\n';
                            if (t[j].X == -1) {
                                flag = 1;
                                break;
                            }
                            tcol[ a[j].X ][ a[j].Y ] = 0;
                            tcol[ t[j].X ][ t[j].Y ] = 1;
                            ll tmp = t[j].X * n + t[j].Y;
                            mask = (mask + (tmp * seedP[j]) % mod) % mod;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
            } else if (i == 2) {
                for (int row = n-1; row >= 0; row--) {
                    for (int col = 0; col < n; col++) {
                        if (Ccol[row][col]) {
                            int j = num[row][col];
                            t[j] = Move(n, a[j].X, a[j].Y, i, j, 0);
                            if (t[j].X == -1) {
                                flag = 1;
                                break;
                            }
                            tcol[ a[j].X ][ a[j].Y ] = 0;
                            tcol[ t[j].X ][ t[j].Y ] = 1;
                            ll tmp = t[j].X * n + t[j].Y;
                            mask = (mask + (tmp * seedP[j]) % mod) % mod;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
            } else {
                for (int row = n-1; row >= 0; row--) {
                    for (int col = n-1; col >= 0; col--) {
                        if (Ccol[row][col]) {
                            int j = num[row][col];
                            t[j] = Move(n, a[j].X, a[j].Y, i, j, 0);
                            if (t[j].X == -1) {
                                flag = 1;
                                break;
                            }
                            tcol[ a[j].X ][ a[j].Y ] = 0;
                            tcol[ t[j].X ][ t[j].Y ] = 1;
                            ll tmp = t[j].X * n + t[j].Y;
                            mask = (mask + (tmp * seedP[j]) % mod) % mod;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
            }

            if (flag) continue;

//            cout << "i = " << i << '\n';

            for (int j = 0; j < m; j++) {
                if (ishole[t[j].X][t[j].Y] != j) {
                    flag = 1;
                    break;
                }
            }

            if (!flag) {
                return dist[state] + 1;
            }
//            cout << "state = " << state << " mask = " << mask << '\n';
            if (dist.find(mask) == dist.end() || dist[mask] > dist[state] + 1) {
//                cout << "state = " << state << " mask = " << mask << '\n';
                dist[mask] = dist[state] + 1;
                tq.push(mask);
                for (int j = 0; j < m; j++) {
                    Q.push(t[j]);
                }
            }
        }
    }

    return -1;
}

void pre (ll seed) {
    seedP[0] = 1;
    for (int i = 1; i < 18; i++) {
        seedP[i] = (seedP[i-1] * seed) % mod;
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test = 0;
    int n, m, w;

    while (scanf("%d %d %d", &n, &m, &w) == 3 && (n || w || m)) {
        queue <pii> Q;

        seed = 17;
        pre(seed);
        ll now = 0;

        vector <pii> v;

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            Q.push({a, b});
            ll tmp = a * n + b;
            now = (now + (tmp * seedP[i]) % mod) % mod;
            v.pb({a, b});
        }

        mem(ishole, -1);

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &hole[i].X, &hole[i].Y);
            ishole[hole[i].X][hole[i].Y] = i;
        }

        for (int i = 0; i < w; i++) {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            forbid[a][b][c][d] = forbid[c][d][a][b] = 1;
        }

        int k = bfs(n, m, Q, now);

        seed = 29;
        pre(seed);
        now = 0;

        while (!Q.empty()) Q.pop();

        for (int i = 0; i < m; i++) {
            Q.push({v[i].X, v[i].Y});
            ll tmp = v[i].X * n + v[i].Y;
            now = (now + (tmp * seedP[i]) % mod) % mod;
        }

        int k1 = bfs(n, m, Q, now);

//        printf("k = %d k1 = %d\n", k, k1);

        if (k == -1 || k1 == -1 || k != k1) printf("Case %d: impossible\n\n", ++test);
        else printf("Case %d: %d moves\n\n", ++test, k);
    }

    return 0;
}

/*
4 3 1
0 1
1 0
1 2
2 3
2 1
3 2
1 1 1 2

4 3 1
2 0
3 0
3 2
2 3
2 1
3 2
1 1 1 2
*/





