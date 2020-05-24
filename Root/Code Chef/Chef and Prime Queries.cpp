#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 2000010

vector <int> prime;
bool arr[SZ];

void sieve() {
    int lim = sqrt(1000000);
    for (int i = 3; i <= lim; i++) {
        if (!arr[i])
        for (int j = i * i; j <= 1000000; j += i + i) {
            arr[j] = 1;
        }
    }
    prime.pb(2);
    for (int i = 3; i <= 1000000; i += 2) {
        if (!arr[i]) prime.pb(i);
    }
    return;
}

void factorize(int n, vector <int>& a, int& now) {
    for (int i = 0; i < sz(prime) && (ll)prime[i] * (ll)prime[i] <= n; i++) {
        while (n % prime[i] == 0) {
            n /= prime[i];
            a[++now] = prime[i];
        }
    }
    if (n != 1) {
        a[++now] = n;
    }
    return;
}

struct data {
    int type, x, l, r, serial;
    data () {}
    data (int a, int b, int c, int d, int e) {
        type = a, x = b, l = c, r = d, serial = e;
    }
};

bool comp (data p, data q) {
    if (p.x == q.x) return p.type < q.type;
    return p.x > q.x;
}

int tree[4 * SZ];

void update (int node, int b, int e, int x) {
    if (b == e) tree[node] = 1;
    else {
        int mid = (b + e) / 2;
        if (x <= mid) update(2 * node, b, mid, x);
        else update(2 * node + 1, mid + 1, e, x);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    return;
}

int query (int node, int b, int e, int f, int t) {
    int ans = 0;
    if (b >= f && e <= t) ans = tree[node];
    else {
        int mid = (b + e) / 2;
        if (f <= mid) ans = query(2 * node, b, mid, f, t);
        if (t > mid) ans += query(2 * node + 1, mid + 1, e, f, t);
    }
    return ans;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    sieve();

    int n;
    scanf("%d", &n);

    vector <int> a(n * 20);
    vector <int> strt(n + 2), endd(n + 2);

    int now = 0;
    for (int i = 1; i <= n; i++) {
        strt[i] = now + 1;
        int x;
        scanf("%d", &x);
        factorize(x, a, now);
        endd[i] = now;
    }

    vector <data> part1, part2;

    for (int i = 1; i <= now; i++) {
        part1.pb(data(0, a[i], i, 0, 0));
        part2.pb(data(0, a[i], i, 0, 0));
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int l, r, x, y;
        scanf("%d %d %d %d", &l, &r, &x, &y);
        part1.pb(data(1, x, strt[l], endd[r], i));
        part2.pb(data(1, y + 1, strt[l], endd[r], i));
    }

    sort(part1.begin(), part1.end(), comp);
    sort(part2.begin(), part2.end(), comp);

    vector <int> ans(q, 0);

    for (int i = 0; i < now + q; i++) {
        if (part1[i].type == 0) {
            update(1, 1, now, part1[i].l);
        } else {
            ans[part1[i].serial] = query(1, 1, now, part1[i].l, part1[i].r);
        }
    }

    mem(tree, 0);


    for (int i = 0; i < now + q; i++) {
        if (part2[i].type == 0) {
            update(1, 1, now, part2[i].l);
        } else {
            ans[part2[i].serial] -= query(1, 1, now, part2[i].l, part2[i].r);
        }
    }

    for (auto x: ans) printf("%d\n", x);

    return 0;
}




