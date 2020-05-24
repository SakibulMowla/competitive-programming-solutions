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

string str;
int two[SZ];
int tree[4*SZ];

void build (int node, int b, int e) {
    if (b == e) {
        tree[node] = str[b]-'0';
    } else {
        int mid = (b + e) >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        tree[node] = (tree[2 * node] * two[e-mid] + tree[2 * node + 1]) % 3;
    }
    return;
}

void update (int node, int b, int e, int pos) {
    if (b == e) {
        if (tree[node] == 0) {
            tree[node] = 1;
        }
    } else {
        int mid = (b + e) >> 1;
        if (pos <= mid) update(2 * node, b, mid, pos);
        else update(2 * node + 1, mid + 1, e, pos);
        tree[node] = (tree[2 * node] * two[e-mid] + tree[2 * node + 1]) % 3;
    }
    return;
}

pii query (int node, int b, int e, int f, int t) {
    if (b>=f && e<=t) {
        return {tree[node], e-b+1};
    } else {
        int mid = (b + e) >> 1;
        pii A, B;
        int f1 = 0, f2 = 0;
        if (f <= mid) {
            f1 = 1;
            A = query(2 * node, b, mid, f, t);
        }
        if (t > mid) {
            f2 = 1;
            B = query(2 * node + 1, mid + 1, e, f, t);
        }
        if (f1 + f2 == 2) {
            pii c;
            c.Y = A.Y + B.Y;
            c.X = (A.X * two[B.Y] + B.X) % 3;
            return c;
        }
        if (f1 == 1) return A;
        return B;
    }
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    two[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        two[i] = (2 * two[i-1]) % 3;
    }

    int n;
    cin >> n;
    cin >> str;

    build(1, 0, n - 1);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r).X << endl;
        } else {
            int l;
            cin >> l;
            update(1, 0, n - 1, l);
        }
    }


    return 0;
}



