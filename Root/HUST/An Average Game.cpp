#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 10010

struct data {
    int l, r, idx, typ;
    data (int _l, int _r, int _idx, int _typ) {
        l = _l, r = _r, idx = _idx, typ = _typ;
    }
};

bool comp (data a, data b) {
    if (a.r == b.r) {
        return a.typ < b.typ;
    }
    return a.r < b.r;
}

ll a[SZ];
vector <data> v;
map <int, int> mp;
double ans[SZ];

ll sum[4*SZ];
int cnt[4*SZ];

ll _sum, _cnt;

void query (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) {
        _sum += sum[node];
        _cnt += cnt[node];
    } else {
        int mid = (b + e) >> 1;
        if (f <= mid) query(2 * node, b, mid, f, t);
        if (t > mid) query(2 * node + 1, mid + 1, e, f, t);
    }
    return;
}

void update (int node, int b, int e, int pos) {
    if (b == e) {
        cnt[node] = 0;
        sum[node] = 0;
    } else {
        int mid = (b + e) >> 1;
        if (pos <= mid) update(2 * node, b, mid, pos);
        else update(2 * node + 1, mid + 1, e, pos);
        sum[node] = sum[2 * node] + sum[2 * node + 1];
        cnt[node] = cnt[2 * node] + cnt[2 * node + 1];
    }
    return;
}

void update (int node, int b, int e, int pos, ll val) {
//    cout << "at >> " << node << " " << b << " " << e << " " << pos << " " << val << endl;
    if (b == e) {
        cnt[node] = 1;
        sum[node] = val;
    } else {
        int mid = (b + e) >> 1;
        if (pos <= mid) update(2 * node, b, mid, pos, val);
        else update(2 * node + 1, mid + 1, e, pos, val);
        sum[node] = sum[2 * node] + sum[2 * node + 1];
        cnt[node] = cnt[2 * node] + cnt[2 * node + 1];
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        clr(v);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            v.pb(data(a[i], i, i, 0));
        }

        int q;
        cin >> q;

        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            v.pb(data(l - 1, r - 1, i, 1));
        }

        sort(v. begin(), v.end(), comp);
        clr(mp);
        mem(sum, 0);
        mem(cnt, 0);

        for (int i = 0; i < sz(v); i++) {
            if (v[i].typ == 0) {
//                cout << "1 >> " << v[i].l << " " << v[i].r << " " << v[i].idx << " " << v[i].typ << endl;
                if (mp.find(v[i].l) != mp.end()) {
                    update(1, 0, n - 1, mp[v[i].l]);
                }
                mp[v[i].l] = v[i].idx;
                update(1, 0, n - 1, v[i].idx, (ll)v[i].l);
            } else {
//                cout << "2 >> " << v[i].l << " " << v[i].r << " " << v[i].idx << " " << v[i].typ << endl;
                _sum = _cnt = 0;
                query(1, 0, n-1, v[i].l, v[i].r);
//                cout << "sum = " << _sum << " cnt = " << _cnt << endl;
                ans[v[i].idx] = (double)_sum / (double)_cnt;
            }
        }

        cout << "Case " << cs + 1 << ":" << endl;
        for (int i = 0; i < q; i++) {
            cout << fixed << setprecision(6) << ans[i] << endl;
        }
    }


    return 0;
}


/*
2
10
1 2 3 4 4 3 2 1 -1 0
4
1 4
1 10
3 5
8 10
3
1 1 0
1
1 3
*/




