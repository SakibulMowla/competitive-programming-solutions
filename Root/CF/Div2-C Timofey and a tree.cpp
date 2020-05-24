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

vector <int> G[SZ];
vector <int> col;

int candidate1, candidate2;

void dfs (int u, int p) {
    for (int i = 0; i < sz(G[u]); i++) {
        int v = G[u][i];
        if (v != p) {
            if (col[v] != col[u]) {
                candidate1 = u;
                candidate2 = v;
            } else {
                dfs(v, u);
            }
        }
    }
    return;
}

bool isPossible (int u, int p, int c) {
    for (int i = 0; i < sz(G[u]); i++) {
        int v = G[u][i];
        if (v != p) {
            if (col[v] != col[u]) {
                return false;
            } else {
                bool tmp = isPossible (v, u, c);
                if (tmp == false) return false;
            }
        }
    }
    return true;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u - 1].pb(v - 1);
        G[v - 1].pb(u - 1);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        col.pb(x);
    }

    candidate1 = 0;
    candidate2 = 0;

    dfs(0, 0);
    bool flag = true;

    for (int i = 0; i < sz(G[candidate1]); i++) {
        if (!isPossible(G[candidate1][i], candidate1, col[G[candidate1][i]])) {
            flag = false;
            break;
        }
    }

//    cout << ">> " << candidate1 << ' ' << candidate2 << endl;

    if (flag) {
        cout << "YES" << endl;
        cout << candidate1 + 1 << endl;
    } else {
        for (int i = 0; i < sz(G[candidate2]); i++) {
            if (!isPossible(G[candidate2][i], candidate2, col[G[candidate2][i]])) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << "YES" << endl;
            cout << candidate2 + 1 << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}





