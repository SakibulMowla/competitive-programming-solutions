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

    vector <ll> v(n), d(n), p(n), id(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> d[i] >> p[i];
        id[i] = i + 1;
    }

    vector <int> a;

    for (int i = 0; i < n; i++) {
        if (p[i] < 0) continue;
        a.pb(id[i]);

        ll k = v[i], cut = 0;
        for (int j = i + 1; j < n; j++, k--) {
            if (k < 0) {
                k = 0;
            }
            if (p[j] < 0 && k != 0) {
                k++;
            }
            if (p[j] >= 0) {
                p[j] -= (k + cut);
                if (p[j] < 0) {
                    cut += d[j];
                }
            }
        }
    }

    cout << sz(a) << endl;
    for (auto x: a) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}

/*
10
10 7 10
3 6 11
8 4 10
10 1 11
7 3 13
7 2 13
7 6 14
3 4 17
9 4 20
5 2 24
*/



