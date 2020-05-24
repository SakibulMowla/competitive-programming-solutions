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
    cin >> a >> b;

    int n1 = a.size(), n2 = b.size();

    a = '#' + a;
    b = '#' + b;

    vector <int> L(n2 + 2, -1), R(n2 + 2, -1);

    for (int i = 1, j = 1; j <= n2; j++) {
        for (; i <= n1; i++) {
            if (a[i] == b[j]) {
                L[j] = i;
                i++;
                break;
            }
        }
    }

    int jlast = n2 + 1;
    for (int i = n1, j = n2; j >= 1; j--) {
        for (; i >= 1; i--) {
            if (a[i] == b[j]) {
                R[j] = i;
                i--;
                jlast = j;
                break;
            }
        }
    }

    int mx = 0, endd = 0, strt = n2 + 1;
    L[0] = 0;
    R[n2 + 1] = n1 + 1;

    for (int i = 0, j = jlast; i <= n2 && L[i] != -1; i++) {
        while (j <= n2 && R[j] <= L[i]) {
            j++;
        }
        if (i < j && L[i] < R[j] && i + n2 - j + 1 > mx) {
            mx = i + n2 - j + 1;
            strt = j;
            endd = i;
        }
    }

    if (!mx) {
        cout << "-" << endl;
    } else {
        for (int i = 1; i <= endd; i++) {
            cout << b[i];
        }
        for (int i = strt; i <= n2; i++) {
            cout << b[i];
        }
        cout << endl;
    }

    return 0;
}

