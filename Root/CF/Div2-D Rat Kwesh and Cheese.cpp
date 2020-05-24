#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

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
#define EPS 1e-15

ld cal1 (ld x, ld y, ld z) {
    return pow(y, z) * log(x);
}

ld cal2 (ld x, ld y, ld z) {
    return y * z * log(x);
}

void print1 (char a, char b, char c) {
    cout << a << '^' << b << '^' << c << endl;
}

void print2 (char a, char b, char c) {
    cout << '(' << a << '^' << b << ')' << '^' << c << endl;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    ld x, y, z;
    while (cin >> x >> y >> z) {
        vector <ld> a(12);

        a[0] = cal1(x, y, z);
        a[1] = cal1(x, z, y);
        a[2] = cal2(x, y, z);
        a[3] = cal2(x, z, y);

        a[4] = cal1(y, x, z);
        a[5] = cal1(y, z, x);
        a[6] = cal2(y, x, z);
        a[7] = cal2(y, z, x);

        a[8] = cal1(z, x, y);
        a[9] = cal1(z, y, x);
        a[10] = cal2(z, x, y);
        a[11] = cal2(z, y, x);

        int indx = 0;
        for (int i = 0; i < 12; i++) {
            if (a[i] > a[indx] + EPS) {
                indx = i;
            }
        }


        if (indx == 0) print1('x', 'y', 'z');
        else if (indx == 1) print1('x', 'z', 'y');
        else if (indx == 2) print2('x', 'y', 'z');
        else if (indx == 3) print2('x', 'z', 'y');

        else if (indx == 4) print1('y', 'x', 'z');
        else if (indx == 5) print1('y', 'z', 'x');
        else if (indx == 6) print2('y', 'x', 'z');
        else if (indx == 7) print2('y', 'z', 'x');

        else if (indx == 8) print1('z', 'x', 'y');
        else if (indx == 9) print1('z', 'y', 'x');
        else if (indx == 10) print2('z', 'x', 'y');
        else if (indx == 11) print2('z', 'y', 'x');

        else assert(indx != -1);
    }


    return 0;
}





