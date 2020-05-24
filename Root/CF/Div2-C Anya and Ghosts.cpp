#include <bits/stdc++.h>

using namespace  std;

#define mem(a,b) memset(a, b, sizeof(a))

#define SZ 2010

int tree[SZ];

int query (int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= x & -x;
    }
    return sum;
}

void update (int x, int v, int n) {
    while (x <= n) {
        tree[x] += v;
        x += x & -x;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int m, t, r;
    while (cin >> m >> t >> r) {
        int ans = 0;
        if (t < r) {
            for (int i = 0; i < m; i++) {
                int w;
                cin >> w;
            }
            ans = -1;
        } else {
            mem(tree, 0);
            for (int i = 0; i < m; i++) {
                int w;
                cin >> w;
                w += 400;
                int now = query(w);
                if (now < r) {
                    int lim = r - now;
                    for (int j = 0; j < lim; j++) {
                        update(w-j, 1, 1000);
                        update(w-j+t, -1, 1000);
                    }
                    ans += lim;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}






