#include <iostream>
#include <vector>
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
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int mx = numeric_limits <int> :: max(), mn = numeric_limits <int> :: min();
    int xs = 0, mnx = mx, mny = mx, mxx = mn, mxy = mn;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == 'X') {
                xs++;
                mnx = min(mnx, i);
                mxx = max(mxx, i);
                mny = min(mny, j);
                mxy = max(mxy, j);
            }
        }
    }

    cout << (xs == ((mxx - mnx + 1) * (mxy - mny + 1))? "YES": "NO") << endl;

    return 0;
}





