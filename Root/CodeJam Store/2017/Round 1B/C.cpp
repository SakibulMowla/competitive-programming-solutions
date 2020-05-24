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

#define SZ 102


int main() {
//    #if defined JESI
        //freopen("C-large-practice.in", "r", stdin);
        //freopen("3.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, q;
        cin >> n >> q;

        vector <pii> horse(n);
        for (int i = 0; i < n; i++) {
            cin >> horse[i].X >> horse[i].Y;
        }

        vector < vector <ll> > mat(n, vector <ll> (n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][k] != -1 && mat[k][j] != -1 && (mat[i][j] == -1 || mat[i][j] > mat[i][k] + mat[k][j])) {
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }

        vector < vector <double> > dist(n, vector <double> (n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != -1 && mat[i][j] <= horse[i].X) {
                    dist[i][j] = (double)mat[i][j] / (double)horse[i].Y;
                }
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != -1 && dist[k][j] != -1 && (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j])) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        cout << "Case #" << cs + 1 << ":";
        for (int i = 0; i < q; i++) {
            int from, to;
            cin >> from >> to;
            cout << fixed << setprecision(10) << " " << dist[from - 1][to - 1];
        }
        cout << endl;
    }

    return 0;
}






