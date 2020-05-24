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
    string s;
    cin >> n >> s;

    queue <int> U, D;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') U.push(i);
        else D.push(i);
    }

    while (sz(U) && sz(D)) {
        int u = U.front(); U.pop();
        int d = D.front(); D.pop();

        if (u < d) {
            U.push(u + n);
        } else {
            D.push(d + n);
        }
    }

    if (sz(U) == 0) {
        cout << 'D' << endl;
    } else {
        cout << 'R' << endl;
    }

    return 0;
}

