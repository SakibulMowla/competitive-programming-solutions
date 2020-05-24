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

//    ios::sync_with_stdio(false);

    char arr[100];

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int p, q, k, a, b;
        scanf("%d %d/%d", &k, &p, &q);
        if (q == 1) {
            a = 1;
            b = p + 1;
        } else if (q > p) {
            a = q;
            b = q - p;
        } else {
            int n = p / q;
            a = q;
            b = (2 * n + 1) * q - p;
        }
        cout << k << ' ' << a << '/' << b << endl;
    }

    return 0;
}





