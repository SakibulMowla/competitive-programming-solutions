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



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "a a" << endl;
        return 0;
    }

    vector <int> two(21, 1);
    for (int i = 1; i <= 20; i++) two[i] = 2 * two[i - 1];

    int len;
    for (int i = 20; i >= 0; i--) {
        if (two[i] <= n) {
            len = i;
            n -= two[i];
            break;
        }
    }

    string s = "";
    for (int i = 0; i < len; i++) {
        s = s + (char)(i + 'a');
        s = s + (char)(i + 'a');
    }

    for (int i = len - 1, needed = 1, strt = len - 1; i >= 0; i--, needed++, strt--) {
        if (n - two[i] >= 0) {
            n -= two[i];
            for (int j = 0; j < needed; j++) {
                s += (char)(j + strt + 'a');
            }
        }
    }

    cout << s << ' ';
    for (int i = 0; i < len; i++) {
        cout << (char)(i + 'a');
    }
    cout << endl;

    return 0;
}




