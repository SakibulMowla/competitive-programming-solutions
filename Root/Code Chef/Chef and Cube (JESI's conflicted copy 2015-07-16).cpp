#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010

enum {front, back, lft, rght, top, bottom};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    vector < vector <int> > mat(6, vector <int> (6, 1));

    mat[lft][rght] = mat[rght][lft] = 0;
    mat[front][back] = mat[back][front] = 0;
    mat[top][bottom] = mat[bottom][top] = 0;

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        vector <string> color(6);
        for (int i = 0; i < 6; i++) {
            cin >> color[i];
        }
        bool flag = false;
        int lim = (1 << 6);
        for (int i = 0; i < lim; i++) {
            if (__builtin_popcount(i) == 3) {
                vector <int> a;
                for (int j = 0; j < 6; j++) {
                    if (i & (1<<j)) {
                        a.pb(j);
                    }
                }
                if (mat[a[0]][a[1]] && mat[a[1]][a[2]] && mat[a[2]][a[0]] && color[a[0]] == color[a[1]] && color[a[1]] == color[a[2]]) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}





