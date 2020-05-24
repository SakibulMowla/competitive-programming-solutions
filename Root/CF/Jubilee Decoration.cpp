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

#define SZ 100010


int main() {
//    #if defined JESI
        freopen("jubilee.in", "r", stdin);
        freopen("jubilee.out", "w", stdout);
//    #endif

    int n;
    while (cin >> n && n) {
        if (n == 3) {
            cout << 1 << endl;
            cout << "1 1 1" << endl;
            cout << "1 1 1" << endl;
        } else if (n == 4) {
            cout << 2 << endl;
            cout << "1 1 2 2" << endl;
            cout << "1 2 1 2" << endl;
        } else if (n == 5) {
            cout << 2 << endl;
            cout << "2 1 1 1 2" << endl;
            cout << "1 2 1 2 1" << endl;
        } else if (n == 6) {
            cout << 2 << endl;
            cout << "1 1 1 2 2 2" << endl;
            cout << "1 2 1 2 1 2" << endl;
        } else {
            cout << 3 << endl;
            for (int i = 0; i < n; i++) {
                cout << (i % 2) + 1 << (i < n - 1? ' ' : '\n');
            }
            for (int i = 0; i < n; i++) {
                cout << 3 << (i < n - 1? ' ' : '\n');
            }
        }
    }


    return 0;
}







