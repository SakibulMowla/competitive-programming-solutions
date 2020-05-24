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


#define SZ 110

char grid[3][SZ];
bool visited[3][SZ];

bool possible (int n, int r, int c) {
    if (c >= n - 1) return true;

    if (visited[r][c]) return false;
    visited[r][c] = true;

    bool ret = false;
    if (grid[r][c+1] == '.') {
        for (int i = -1; i <= 1; i++) {
            int nr = r + i;
            if (nr >= 0 && nr <= 2) {
                if (grid[nr][c + 3] == '.' && grid[nr][c + 1] == '.' && grid[nr][c + 2] == '.') {
                    if (possible(n, nr, c + 3)) {
                        ret = true;
                        break;
                    }
                }
            }
        }
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        int r, c;

        for (int i = 0; i < 3; i++) {
            scanf(" %s", grid[i]);
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 's') {
                    r = i;
                    c = j;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = n; j < n + 2; j++) {
                grid[i][j] = '.';
            }
        }

        mem(visited, 0);
        cout << (possible(n, r, c)? "YES": "NO") << endl;
    }


    return 0;
}





