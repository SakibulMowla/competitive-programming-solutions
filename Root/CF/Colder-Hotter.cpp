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

int FindX () {
    ll lo = 0, hi = 1E9;
    int lim = 100;

    while (lim--) {
        ll m1 = (2 * lo + hi) / 3;
        ll m2 = (lo + 2 * hi) / 3;

//        cout << ">> " << m1 << ' ' << m2 << endl;
//        cout << ">> " << lo << ' ' << hi << endl;

        int a1;
        cout << 0 << ' ' << m1 << endl;
        cout.flush();
        cin >> a1;

        int a2;
        cout << 0 << ' ' << m2 << endl;
        cout.flush();
        cin >> a2;

        if (a2 == 0) {
            hi = m2;
        } else {
            lo = m1;
        }
    }

    return lo;
}

int FindY () {
    ll lo = 0, hi = 1E9;
    int lim = 100;

    while (lim--) {
        ll m1 = (2 * lo + hi) / 3;
        ll m2 = (lo + 2 * hi) / 3;

        int a1;
        cout << m1 << ' ' << 0 << endl;
        cout.flush();
        cin >> a1;

        int a2;
        cout << m2 << ' ' << 0 << endl;
        cout.flush();
        cin >> a2;

        if (a2 == 0) {
            hi = m2;
        } else {
            lo = m1;
        }
    }

    return lo;
}



int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int y = FindX();
    int x = FindY();

    cout << x << ' ' << y << endl;
    cout.flush();

    int z;
    cin >> z;

    int xx = x, yy = y;

    for (int i = max(0, x - 3); i <= min(x + 3, (int)1E9); i++) {
        for (int j = max(0, y - 3); j <= min((int) 1E9, y + 3); j++) {
            cout << xx << ' ' << yy << endl;
            cout.flush();
            cin >> z;

            cout << i << ' ' << j << endl;
            cout.flush();
            cin >> z;
            if (z == 1) {
                xx = i;
                yy = j;
            }
        }
    }

    cout << 'A' << ' ' << xx << ' ' << yy << endl;
    cout.flush();


    return 0;
}




