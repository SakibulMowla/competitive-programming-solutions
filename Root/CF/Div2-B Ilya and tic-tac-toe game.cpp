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

bool check (int i, int j, vector <string>& v) {
    return (i >= 0 && i < 4 && j >= 0 && j < 4 && v[i][j] == 'x');
}

bool solve (vector <string>& v) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((check(i, j, v) && check(i, j + 1, v) && check(i, j + 2, v)) ||
                (check(i, j, v) && check(i + 1, j, v) && check(i + 2, j, v)) ||
                (check(i, j, v) && check(i + 1, j + 1, v) && check(i + 2, j + 2, v)) ||
                (check(i, j, v) && check(i + 1, j - 1, v) && check(i + 2, j - 2, v)))
                    return true;
        }
    }
    return false;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    vector <string> v(4);
    for (int i = 0; i < 4; i++) {
        cin >> v[i];
    }

    bool flag = false;
    for (int i = 0; i < 4 && !flag; i++) {
        for (int j = 0; j < 4 && !flag; j++) {
            if (v[i][j] == '.') {
                v[i][j] = 'x';
                flag = solve(v);
//                cout << ">> " << i << ' ' << j << endl;
                v[i][j] = '.';
            }
        }
    }
    cout << (flag? "YES": "NO") << endl;

    return 0;
}




