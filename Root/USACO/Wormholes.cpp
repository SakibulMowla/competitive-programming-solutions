/*
ID: sakibul1
PROG: wormhole
LANG: C++
*/

#include "bits/stdc++.h"

using namespace std;

#define SZ 20

#define X first
#define Y second

pair <int , int> a[SZ];
int nxt[SZ];
int par[SZ];
int n;

bool isCycle () {
    for (int i = 1; i <= n; i++) {
        int now = i;
        for (int j = 0; j < n; j++)
            now = nxt[ par[ now ] ];
        if (now != 0)
            return true;
    }
    return false;
}

int bctk () {
    int i;
    for (i = 1; i <= n; i++) {
        if (par[i] == -1) {
            break;
        }
    }
    if (i > n) {
        return isCycle();
    }
    int ans = 0;
    for (int j = i + 1; j <= n; j++) {
        if (par[j] == -1) {
            par[i] = j;
            par[j] = i;
            ans += bctk();
            par[i] = -1;
            par[j] = -1;
        }
    }
    return ans;
}

int main() {
//    freopen("wormhole.in", "r", stdin);
//    freopen("wormhole.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].X >> a[i].Y;
    }

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i].Y == a[j].Y && a[j].X > a[i].X) {
                if (nxt[i] == 0 || a[j].X - a[i].X < a[ nxt[i] ].X - a[i].X) {
                    nxt[i] = j;
                }
            }
        }
    }

    memset(par, -1, sizeof par);
    cout << bctk() << '\n';

    return 0;
}


