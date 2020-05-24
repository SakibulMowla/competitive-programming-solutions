#include <bits/stdc++.h>

using namespace std;

using pii = pair <int, int>;

#define X first
#define Y second

struct SegTree {
    int n;
    vector <int> lazy;

    SegTree (int n): n(n), lazy(4 * n + 10, 0) {
        ;
    }

    void propagate (int node, int b, int e) {
        if (lazy[node]) {
            if (b < e) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        return;
    }

    void update (int node, int b, int e, int f, int t, int val) {
        if (b >= f && e <= t) {
            lazy[node] += val;
        } else {
            propagate(node, b, e);
            int mid = (b + e) >> 1;
            if (f <= mid) update(2 * node, b, mid, f, t, val);
            if (t > mid) update(2 * node + 1, mid + 1, e, f, t, val);
        }
        return;
    }

    int query (int node, int b, int e, int x) {
        if (b == e) {
            return lazy[node];
        } else {
            propagate(node, b, e);
            int mid = (b + e) >> 1;
            if (x <= mid) return query(2 * node, b, mid, x);
            else return query(2 * node + 1, mid + 1, e, x);
        }
    }
};

struct Solve {
    vector <pii> pnt;
    vector <int> tmp;
    int n, k;

    Solve (int n, int k): n(n), k(k), pnt(n) {
        for (int i = 0; i < n; i++) {
            cin >> pnt[i].X >> pnt[i].Y;
            pnt[i].Y--;
            tmp.push_back(pnt[i].X);
            tmp.push_back(pnt[i].Y);
        }

        sort(tmp.begin(), tmp.end());
        tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());

        for (int i = 0; i < n; i++) {
            pnt[i].X = lower_bound(tmp.begin(), tmp.end(), pnt[i].X) - tmp.begin();
            pnt[i].Y = lower_bound(tmp.begin(), tmp.end(), pnt[i].Y) - tmp.begin();
        }


        sort(pnt.begin(), pnt.end());
        cout << solve() << endl;
    }

    int solve () {
        SegTree ST(tmp.size());
        auto comp = [](const pii &a, const pii &b){return a.Y > b.Y;};
        multiset <pii, decltype(comp)> ms(comp);

        int ans = n;
        int lim = tmp.size();

        for (int i = 0; i < n; i++) {
            ST.update(1, 0, lim - 1, pnt[i].X, pnt[i].Y, 1);
            ms.insert(pnt[i]);
            int now = ST.query(1, 0, lim - 1, pnt[i].X);
            if (now == k + 1) {
                ans--;
                auto it = ms.begin();
                ST.update(1, 0, lim - 1, it->X, it->Y, -1);
                ms.erase(it);
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    Solve Task(n, k);

    return 0;
}
