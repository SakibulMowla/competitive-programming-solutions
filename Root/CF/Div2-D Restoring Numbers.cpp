#include <bits/stdc++.h>

using namespace  std;

using ll = long long int;
using VI = vector <int>;
using VVI = vector < vector <int> >;

#define SZ 110

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int n, m;
    cin >> n >> m;

    VVI w = VVI(n, VI(m));
    VI a = VI(n);
    VI b = VI(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> w[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        b[i] = w[0][i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = w[i][0] - b[0];
    }

    ll g = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g = __gcd(g, llabs(a[i] + b[j] - w[i][j]));
        }
    }

    if (g) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g <= w[i][j]) {
                    cout << "NO\n";
                    goto HELL;
                }
            }
        }
    } else {
        g = 1E9 + 1;
    }

    cout << "YES\n" << g << '\n';
    for (auto i : a) {
        cout << ((i % g) + g) % g << ' ';
    }
    cout << '\n';
    for (auto j : b) {
        cout << ((j % g) + g) % g << ' ';
    }
    cout << '\n';

    HELL:;

    return 0;
}






