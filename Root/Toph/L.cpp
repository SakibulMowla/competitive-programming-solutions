#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

using namespace std;
using ll = long long;

int n;
int tree[62][100010];
ll a[100010];

void update(int indx, int val, int bit) {
    while(indx <= n) {
        tree[bit][indx] += val;
        indx += (indx & -indx);
    }
}

int query(int indx, int bit) {
    int sum = 0;
    while(indx > 0) {
        sum += tree[bit][indx];
        indx -= (indx & -indx);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 61; j++)
            update(i, (a[i] >> j) & 1, j);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int indx, x;
            cin >> indx >> x;
            for (int j = 0; j < 61; j++) {
                update(indx, -((a[indx] >> j) & 1), j);
                update(indx, (x >> j) & 1, j);
            }
            a[indx] = x;
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << query(r, k) - query(l - 1, k) << endl;
        }
    }

    return 0;
}
