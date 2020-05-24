#include <bits/stdc++.h>

using namespace  std;

#define sz(a) (int)a.size()

struct matrix {
    double x[26][26];
};
matrix base, zero;

matrix matmult (matrix &a, matrix &b, int n) {
    matrix ret = zero;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ret.x[i][j] = ret.x[i][j] + (a.x[i][k] * b.x[k][j]);
    return ret;
}

matrix bigmod (matrix power, int p, int n) {
    matrix xx = zero;
    for (int i = 0; i < n; i++) xx.x[i][i] = 1.0;
    while (p) {
        if(p&1) xx = matmult(xx, power, n);
        power = matmult(power, power, n);
        p >>= 1;
    }
    return xx;
}

set <string> ms;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    string a, s;
    matrix ans;

    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> n >> k;
        cin >> a;

        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                cin >> base.x[i][j];

        ms.clear();
        for (int i = 0; i < n; i++) {
            cin >> s;
            ms.insert(s);
        }

        ans = bigmod(base, k, 26);

        double E = 0.0;
        for (set <string>::iterator it = ms.begin(); it != ms.end(); it++) {
            s = *it;
            if(sz(s) != sz(a)) continue;
            double tmp = 1.0;
            for (int j = 0; j < sz(a); j++)
                tmp *= ans.x[a[j]-'a'][s[j]-'a'];
            E += tmp;
        }

        cout << fixed ;
        cout << setprecision(12) << E << '\n';
    }

    return 0;
}



