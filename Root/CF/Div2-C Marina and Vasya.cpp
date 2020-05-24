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

    string a, b;
    int n, k;

    cin >> n >> k;
    cin >> a >> b;

    int mtch = 0;
    k = n - k;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            mtch++;
        }
    }

    int mx = mtch + (n - mtch) / 2;

    if (k > mx) cout << -1 << endl;
    else {
        string c;
        for (int i = 0; i < n; i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                if (j != a[i] && j != b[i]) {
                    c += (char)j;
                    break;
                }
            }
        }

        for (int i = 0; i < n && k; i++) {
            if (a[i] == b[i]) {
                c[i] = a[i];
                k--;
            }
        }

        int k1 = k, i;
        for (i = 0; i < n && k1; i++) {
            if (a[i] != b[i]) {
                c[i] = a[i];
                k1--;
            }
        }

        k1 = k;
        for (; i < n && k1; i++) {
            if (a[i] != b[i]) {
                c[i] = b[i];
                k1--;
            }
        }

        cout << c << endl;
    }

    return 0;
}


