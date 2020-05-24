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

int isFine(int r1, int r2, int c1, int c2, vector<vector<int>>& sum) {
    if (c1 >= c2 || c1 == -1 || c2 == -1) return -1;
    int tot = (r2 - r1 + 1) * (c2 - c1);
    int zero = sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
    int other = tot - zero;
    if (zero <= 1 || other > 1) return tot;
    return -1;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;

    vector<vector<int>> tmp(r + 1, vector<int>(c + 1)), a;
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> tmp[i][j];

    bool sflag = false;

    if (r > c) {
        swap(r, c);
        sflag = true;
        a = vector<vector<int>>(r + 1, vector<int>(c + 1));
        for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) a[i][j] = tmp[j][i];
    } else a = tmp;

    vector<vector<int>> sum(r + 1, vector<int> (c + 1, 0));
    vector<vector<int>> sumB(r + 1, vector<int> (c + 1, 0));

    for (int i = 1; i <= r; i++) {
        int cnt = 0;
        int mask = 0;
        for (int j = 1; j <= c; j++) {
            if (a[i][j] == 0) cnt++;
            sum[i][j] = sum[i - 1][j] + cnt;
            mask ^= (1 << a[i][j]);
            sumB[i][j] = sumB[i - 1][j] ^ mask;
        }
    }

    unordered_map<int, pii> store;
    int best = 1;
    pii ul = {1, 1}, lr = {1, 1};

    for (int i = 1; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            store.clear();
            store[0] = {0, 0};
            for (int k = 1; k <= c; k++) {
                int mask = sumB[j][k] ^ sumB[i - 1][k];
                if (store.find(mask) == store.end()) store[mask] = {k, k};
                else store[mask].Y = k;
            }

            for (auto x: store) {
                int zero = x.Y.X, one = x.Y.Y;
                int now = isFine(i, j, zero, one, sum);
                if (now > best) {
                    best = now;
                    ul = {i, zero + 1};
                    lr = {j, one};
                }
                for (int l = 0; l < 10; l++) {
                    int kp = x.X ^ (1 << l);
                    if (store.find(kp) != store.end()) {
                        now = isFine(i, j, store[kp].X, one, sum);
                        if (now > best) {
                            best = now;
                            ul = {i, store[kp].X + 1};
                            lr = {j, one};
                        }
                        now = isFine(i, j, zero, store[kp].Y, sum);
                        if (now > best) {
                            best = now;
                            ul = {i, zero + 1};
                            lr = {j, store[kp].Y};
                        }
                    }
                }
            }
        }
    }

    if (sflag) {
        swap(ul.X, ul.Y);
        swap(lr.X, lr.Y);
    }

    cout << best << endl;
    cout << ul.X - 1 << ' ' << ul.Y - 1 << ' ' << lr.X - 1 << ' ' << lr.Y - 1 << endl;

    return 0;
}



