#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector <ll> tree;

    SegTree (int n): n(n), tree(4 * n + 4) {}

    void Build (int at, int l, int r, vector <ll>& t) {
        if (l == r) {
            tree[at] = t[l];
        } else {
            int mid = (l + r) / 2;
            Build(2 * at, l, mid, t);
            Build(2 * at + 1, mid + 1, r, t);
            tree[at] = tree[2 * at] + tree[2 * at + 1];
        }
    }

    void Uptdate (int at, int l, int r, int x, ll v) {
        if (l == r) {
            tree[l] += v;
        } else {
            int mid = (l + r) / 2;
            if (x < mid) {
                Uptdate(2 * at, l, mid, x, v);
            } else {
                Uptdate(2 * at + 1, mid + 1, r, x, v);
            }
            tree[at] = tree[at * 2] + tree[at * 2 + 1];
        }
    }

    void AddAfter (int x, ll v) {
        Uptdate(1, 0, n - 1, x, v);
    }

    ll Query (int at, int l, int r, int x) {
        if (r <= x) {
            return tree[at];
        } else if (x < l) {
            return 0;
        } else {
            int mid = (l + r) / 2;
            return Query(2 * at, l, mid, x) +
                   Query(2 * at + 1, mid + 1, r, x);
        }
    }

    ll Query (int x) {
        return Query(1, 0, n - 1, x);
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <ll> t(m);
    vector <int> tidx(m);
    for (int i = 0; i < m; i++)  {
        cin >> t[i];
        tidx[i] = i;
    }

    sort(tidx.begin(), tidx.end(), [&t] (int i, int j) {
        return t[i] < t[j];
    });

    vector <int> d(n), r(n);
    vector <int> idx(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> r[i];
        idx[i] = i;
    }

    sort(idx.begin(), idx.end(), [&d] (int i, int j) {
        return d[i] < d[j];
    });

    SegTree sum(m), skip(m);
    vector <int> ans(n);
    sum.Build(1, 0, m - 1, t);
    auto spent = [&sum, &skip, &d] (int i, int ts) {
        return sum.Query(ts) -
               d[i] * (ts + 1 - skip.Query(ts));
    };
    for (auto i = idx.begin(), j = tidx.begin(); i != idx.end(); i++) {
        // cerr << "a: " << *i << ' ' << d[*i] << ' ' << r[*i] << endl;
        while (j != tidx.end() && t[*j] < d[*i]) {
            // delete t[*j], add 1 skipped at *j
            sum.AddAfter(*j, -t[*j]);
            skip.AddAfter(*j, 1);
            j++;
            // cerr << "d: " << *j << ' ' << t[*j] << endl;
            // cerr << "x: " << sum.Query(0) << sum.Query(1) << sum.Query(2) << endl;
            // cerr << "x: " << skip.Query(0) << skip.Query(1) << skip.Query(2) << endl;
        }

        if (spent(*i, m - 1) < r[*i]) {
            ans[*i] = -1;
            // cerr << *i << ' ' << spent(*i, m - 1) << endl;
        } else {
            int lo = 0, hi = m - 1;

            while (lo < hi) {
                int mid = (lo + hi) / 2;
                // 1 1 2 -> (1, 1) | (2, 2)
                // cerr << "b: " << "#" << *i << " spends "
                // << spent(*i, mid) << " at t#" << mid << endl;
                if (spent(*i, mid) >= r[*i]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            ans[*i] = lo;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
