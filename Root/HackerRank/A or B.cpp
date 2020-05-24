#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

char i2c[200];
int c2i[200];

void prepare () {
    i2c[0] = '0'; i2c[1] = '1'; i2c[2] = '2'; i2c[3] = '3';
    i2c[4] = '4'; i2c[5] = '5'; i2c[6] = '6'; i2c[7] = '7';
    i2c[8] = '8'; i2c[9] = '9'; i2c[10] = 'A'; i2c[11] = 'B';
    i2c[12] = 'C'; i2c[13] = 'D'; i2c[14] = 'E'; i2c[15] = 'F';
    c2i['0'] = 0; c2i['1'] = 1; c2i['2'] = 2; c2i['3'] = 3;
    c2i['4'] = 4; c2i['5'] = 5; c2i['6'] = 6; c2i['7'] = 7;
    c2i['8'] = 8; c2i['9'] = 9; c2i['A'] = 10; c2i['B'] = 11;
    c2i['C'] = 12; c2i['D'] = 13; c2i['E'] = 14; c2i['F'] = 15;
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    prepare();

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        bool start = false;

        int k;
        cin >> k;

        string a, b, c;
        cin >> a >> b >> c;

        int na = sz(a), nb = sz(b), nc = sz(c);
        int n = max(na, max(nb, nc));

        while (na < n) {
            a = '0' + a;
            na++;
        }
        while (nb < n) {
            b = '0' + b;
            nb++;
        }
        while (nc < n) {
            c = '0' + c;
            nc++;
        }

        vector <int> A(n, 0), B(n, 0), C(n, 0);

        for (int i = 0; i < n; i++) {
            A[i] = c2i[a[i]];
        }
        for (int i = 0; i < n; i++) {
            B[i] = c2i[b[i]];
        }
        for (int i = 0; i < n; i++) {
            C[i] = c2i[c[i]];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 3; j >= 0; j--) {
                int x = (A[i] & (1<<j));
                int y = (B[i] & (1<<j));
                int z = (C[i] & (1<<j));
                if (z && !x && !y) {
                    if (k) {
                        k--;
                        B[i] |= (1<<j);
                    } else {
                        cout << -1 << endl;
                        goto HELL;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 3; j >= 0; j--) {
                int x = (A[i] & (1<<j));
                int y = (B[i] & (1<<j));
                int z = (C[i] & (1<<j));
                if (!z) {
                    if (x) {
                        if (k) {
                            A[i] &= (~(1<<j));
                            --k;
                        } else {
                            cout << -1 << endl;
                            goto HELL;
                        }
                    }
                    if (y) {
                        if (k) {
                            B[i] &= (~(1<<j));
                            --k;
                        } else {
                            cout << -1 << endl;
                            goto HELL;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 3; j >= 0; j--) {
                int x = (A[i] & (1<<j));
                int y = (B[i] & (1<<j));
                int z = (C[i] & (1<<j));
                if (z) {
                    if (x && y) {
                        if (k) {
                            k--;
                            A[i] &= (~(1<<j));
                        }
                    } else if (x) {
                        if (k >= 2) {
                            k -= 2;
                            A[i] &= (~(1<<j));
                            B[i] |= (1<<j);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (start) {
                cout << i2c[A[i]];
            } else {
                if (A[i]) {
                    start = true;
                    cout << i2c[A[i]];
                }
            }
        }
        if (!start) cout << 0;
        cout << endl;
        start = false;
        for (int i = 0; i < n; i++) {
            if (start) {
                cout << i2c[B[i]];
            } else {
                if (B[i]) {
                    start = true;
                    cout << i2c[B[i]];
                }
            }
        }
        if (!start) cout << 0;
        cout << endl;

        HELL:;
    }

    return 0;
}



