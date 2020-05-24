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

bool check (vector < vector <int> >& v, int n, int m) {
    for (int i = 0; i < n; i++) {
        int not_in_pos = 0;
        for (int j = 0; j < m; j++) {
            if (j != v[i][j] - 1) {
                not_in_pos++;
            }
        }
        if (not_in_pos > 2) {
            return false;
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

    int n, m;
    cin >> n >> m;

    vector < vector <int> > v(n, vector <int> (m));
    for (auto &x: v) {
        for (auto &y: x) {
            cin >> y;
        }
    }

    bool flag = check(v, n, m);
    if (flag == false) {
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    swap(v[k][i], v[k][j]);
                }
                flag = check(v, n, m);
                for (int k = 0; k < n; k++) {
                    swap(v[k][i], v[k][j]);
                }
                if (flag == true) {
                    j = m;
                    i = m;
                }
            }
        }
    }

    cout << (flag? "YES": "NO") << endl;

    return 0;
}





