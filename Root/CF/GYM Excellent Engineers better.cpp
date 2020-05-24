#include <bits/stdc++.h>

using namespace  std;

const int inf = 1E8;

#define SZ 100010

struct data {
    int b, c;
};

data a[SZ];
int mnz[SZ];

int Query (int idx) {
    int ret = inf;
    while (idx > 0) {
        ret = min(ret, mnz[idx]);
        idx -= (idx & -idx);
    }
    return ret;
}

void Update (int n, int idx, int val) {
    while (idx <= n) {
        mnz[idx] = min(mnz[idx], val);
        idx += (idx & -idx);
    }
    return;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            scanf("%d %d", &a[x].b, &a[x].c);
            mnz[i+1] = inf;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int mn = Query(a[i].b);
            if(a[i].c < mn) ans++;
            Update(n, a[i].b, a[i].c);
        }

        printf("%d\n", ans);
    }

    return 0;
}

