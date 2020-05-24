#include "bits/stdc++.h"

using namespace std;

#define SZ 50010

struct Trie {
    int dir[2];
    Trie () {
        dir[0] = dir[1] = -1;
    }
};

vector <Trie> T;
int cnt;

void Insert (int x) {
    int node = 0;
    for (int i = 31; i >= 0; i--) {
        int now = (x & (1<<i)) != 0;
        if (T[node].dir[now] == -1) {
            T.push_back(Trie());
            T[node].dir[now] = ++cnt;
        }
        node = T[node].dir[now];
    }
    return;
}

int getMin (int x) {
    int node = 0;
    int ret = 0;
    for (int i = 31; i >= 0; i--) {
        int now = (x & (1<<i)) != 0;
        ret <<= 1;
        if (T[node].dir[now] == -1) {
            ret |= (now ^ 1);
            node = T[node].dir[!now];
        } else {
            ret |= now;
            node = T[node].dir[now];
        }
    }
    return ret;
}

int getMax (int x) {
    int node = 0;
    int ret = 0;
    for (int i = 31; i >= 0; i--) {
        int now = (x & (1<<i)) != 0;
        ret <<= 1;
        if (T[node].dir[!now] == -1) {
            ret |= now;
            node = T[node].dir[now];
        } else {
            ret |= (now ^ 1);
            node = T[node].dir[!now];
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        cnt = 0;
        T.clear();
        T.push_back(Trie());
        Insert(0);

        int mx, mn, sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum ^= x;
            if (i == 0) {
                mx = mn = x;
            }
            mn = min(mn, getMin(sum) ^ sum);
            mx = max(mx, getMax(sum) ^ sum);
            Insert(sum);
        }

        cout << "Case " << cs + 1 << ": " << mx << ' ' << mn << '\n';
    }

    return 0;
}
