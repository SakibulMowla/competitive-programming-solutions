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

struct StronglyConnectedComponents {
    int n;
    int totalComponents;
    vector <vector <int>> adj, components;
    vector <int> idx, componentOf, st, low;
    vector <bool> inStack;

    StronglyConnectedComponents (int n): n(n), adj(n) {}

    void AddEdge (int a, int b) {
        adj[a].push_back(b);
    }

    int DFS (int v, int index) {
        idx[v] = index;
        low[v] = index;
        index += 1;
        st.push_back(v);
        inStack[v] = true;

        for (auto& w : adj[v]) {
            if (idx[w] == -1) {
                index = DFS(w, index);
                low[v] = min(low[v], low[w]);
            } else if (inStack[w]) {
                low[v] = min(low[v], low[w]);
            }
        }

        if (low[v] == idx[v]) {
            int w;
            components.push_back(vector <int>());
            do {
                w = st.back();
                st.pop_back();
                inStack[w] = false;
                componentOf[w] = totalComponents;
                components[totalComponents].push_back(w);
            } while (w != v);
            totalComponents++;
        }
        return index;
    }

    void BuildSCC () {
        totalComponents = 0;
        idx = vector <int>(n, -1), low = vector <int>(n), componentOf = vector <int>(n);
        inStack = vector <bool>(n, false);
        st.clear();

        for (int i = 0; i < n; i++) {
            if (idx[i] == -1) {
                DFS(i, 0);
            }
        }
    }

    /*
        Builds an assignment for a 2-SAT problem
        Input:
            - sol, a vector of integers
            - neg, neg[i] is the negation of i
        Output
            - sol, sol[i] will contain the assignment for i {0: false, 1: true}
    */
    void Find2SATSolution (vector <int>& sol, vector <int>& neg) {
        sol = vector <int>(n, -1);
        for (auto& comp : components) {
            for (auto& j : comp) {
                if (sol[j] == -1) {
                    sol[j] = 1;
                    sol[neg[j]] = 0;
                }
            }
        }
    }
};

int dx[] = {0, 1};
int dy[] = {1, 0};

int ddx[] = {-1, 1, 0, 0};
int ddy[] = {0, 0, -1, 1};

void Simulate (vector < vector <int>>& Final, pii P, vector <int>& a, int n, int m) {
    for (int k = 0; k < 4; k++) {
        int u = P.X + ddx[k];
        int v = P.Y + ddy[k];
        if (u >= 0 && u < n && v >= 0 && v < m) {
            if (Final[u][v] != -1) {
                a[Final[u][v]] = 1;
            }
        }
    }
    return;
}

void func (vector < vector <int>>& G, int tromino, int n, int m) {
    vector < vector <pii>> v(tromino);
    vector < vector <int>> Final(n, vector <int> (m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] != -1) {
                v[ G[i][j] ].pb(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < tromino; i++) {
        vector <int> a(4, 0);
        for (int j = 0; j < 3; j++) {
            Simulate(Final, v[i][j], a, n, m);
        }
        for (int k = 0; k < 4; k++) {
            if (a[k] == 0) {
                for (int j = 0; j < 3; j++) {
                    Final[v[i][j].X][v[i][j].Y] = k;
                }
                break;
            }
        }
        assert(sz(v[i]) == 3);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Final[i][j] == 0) cout << 'a';
            else if (Final[i][j] == 1) cout << 'b';
            else if (Final[i][j] == 2) cout << 'c';
            else if (Final[i][j] == 3) cout << 'd';
            else cout << '.';
        }
        cout << endl;
    }
    return;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <string> grid(n);
    vector < vector <int> > num(n, vector <int> (m, -1));
    int wcnt = 0, bcnt = 0;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'b') {
                num[i][j] = bcnt++;
            } else if (grid[i][j] == 'w') {
                wcnt++;
            }
        }
    }

    if (2 * bcnt != wcnt) {
        cout << "NO" << endl;
    } else {
        StronglyConnectedComponents Task(2 * bcnt);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (num[i][j] != -1) {
                    for (int p = 0; p < 2; p++) {
                        for (int x1 = -dx[p]; x1 <= dx[p]; x1++) {
                            for (int y1 = -dy[p]; y1 <= dy[p]; y1++) {
                                if (!(i + x1 >= 0 && i + x1 < n && j + y1 >= 0 && j + y1 < m) ||
                                    (grid[i + x1][j + y1] == '.')) {
                                    Task.AddEdge(num[i][j] + bcnt * p, num[i][j] + bcnt * (!p));
                                    break;
                                }
                            }
                        }
                    }
                    for (int k = max(0, i - 2); k < min(i + 3, n); k++) {
                        for (int l = max(0, j - 2); l < min(j + 3, m); l++) if (num[k][l] != -1 && !(i == k && j == l)) {
                                for (int p = 0; p < 2; p++) {
                                    for (int q = 0; q < 2; q++) {
                                        bool flag = false;
                                        for (int x1 = -dx[p]; x1 <= dx[p]; x1++) {
                                            for (int y1 = -dy[p]; y1 <= dy[p]; y1++) {
                                                for (int x2 = -dx[q]; x2 <= dx[q]; x2++) {
                                                    for (int y2 = -dy[q]; y2 <= dy[q]; y2++) {
                                                        if (i + x1 == k + x2 && j + y1 == l + y2) {
                                                            flag = true;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if (flag) {
                                            Task.AddEdge(num[i][j] + bcnt * p, num[k][l] + bcnt * (!q));
                                            Task.AddEdge(num[k][l] + bcnt * q, num[i][j] + bcnt * (!p));
                                            //cerr << ">> ijklpq = " << i << ' ' << j << ' ' << k << ' ' << l << ' ' << p << ' ' << q << endl;
                                            //cerr << ">> " << num[i][j] << ' ' << num[k][l] << endl;
                                        }
                                    }
                                }
                            }
                    }
                }
        }

        //cerr << ">> HERE" << endl;

        Task.BuildSCC();

        vector <int> sol, neg(2 * bcnt);
        bool mark = true;

        for (int i = 0; i < bcnt; i++) {
            neg[i] = i + bcnt;
            neg[i + bcnt] = i;
            if (Task.componentOf[i] == Task.componentOf[i + bcnt]) {
                //cerr << ">> i = " << i << endl;
                mark = false;
            }
        }

        //cerr << ">> HERE2" << endl;

        if (!mark) {
            cout << "NO" << endl;
        } else {
            Task.Find2SATSolution(sol, neg);
            vector < vector <int> > G(n, vector <int> (m, -1));

            int tromino = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (num[i][j] != -1) {
                        int p = !sol[num[i][j]];
                        for (int x1 = -dx[p]; x1 <= dx[p]; x1++) {
                            for (int y1 = -dy[p]; y1 <= dy[p]; y1++) {
                                ////cerr << ">> " << i + x1 << ' ' << j + y1 << endl;
                                G[i + x1][j + y1] = tromino;
                            }
                        }
                        tromino++;
                    }
                }
            }

            cout << "YES" << endl;
            func(G, tromino, n, m);

//            for (int i = 0; i < n; i++) {
//                for (int j = 0; j < m; j++) {
//                    //cerr << setw(3) << G[i][j] + 1;
//                }
//                //cerr << endl;
//            }
        }
    }

    return 0;
}


