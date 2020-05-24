#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back
#define sz(a) (int)a.size()

#define SZ 100010

const ll inf = 1;
const ll mod = 1;

int a[SZ];

int main () {
    ios::sync_with_stdio(false);

    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l == r) printf("%d\n", a[l]);
        else printf("0\n");
    }

    return 0;
}


