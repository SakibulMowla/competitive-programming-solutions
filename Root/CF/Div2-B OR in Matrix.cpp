#include <iostream>
#include <vector>

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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;

    vector < vector <int> > mat(r, vector <int> (c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    vector <bool> allAreOneRow(r, true), allAreOneCol(c, true);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 1) {
                allAreOneRow[i] = false;
                break;
            }
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (mat[j][i] != 1) {
                allAreOneCol[i] = false;
                break;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 1 && allAreOneCol[j] == false && allAreOneRow[i] == false) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    vector < vector <int> > root(r, vector <int> (c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            root[i][j] = (allAreOneCol[j] == true && allAreOneRow[i] == true);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (root[i][j] == 1) {
                allAreOneCol[j] = false;
                allAreOneRow[i] = false;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        if (allAreOneRow[i] == true) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int i = 0; i < c; i++) {
        if (allAreOneCol[i] == true) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << root[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}





