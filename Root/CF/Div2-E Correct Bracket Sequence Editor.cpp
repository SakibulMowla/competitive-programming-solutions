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


#define SZ 500010

int tree[8 * SZ];
int lazy[8 * SZ];
int lft[SZ];
int rht[SZ];

void build (int node, int b, int e) {
    if (b == e) {
        tree[node] = 1;
    } else {
        int mid = (b + e) / 2;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    return;
}

void Propagate (int node) {
    tree[2 * node] = tree[2 * node + 1] = 0;
    lazy[2 * node] = lazy[2 * node + 1] = 1;
    return;
}

void Delete (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) {
        tree[node] = 0;
        lazy[node] = 1;
    } else {
        if (lazy[node]) {
            Propagate(node);
            lazy[node] = 0;
        }
        int mid = (b + e) / 2;
        if (f <= mid && tree[2 * node]) Delete(2 * node, b, mid, f, t);
        if (t > mid && tree[2 * node + 1]) Delete(2 * node + 1, mid + 1, e, f, t);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    return;
}

string seq, mov;
string ans;

void gather (int node, int b, int e) {
    if (b == e) {
        if (tree[node] == 1) {
            ans = ans + seq[b-1];
        }
    } else {
        if (lazy[node]) {
            Propagate(node);
            lazy[node] = 0;
        }
        int mid = (b + e) / 2;
        gather(2 * node, b, mid);
        gather(2 * node + 1, mid + 1, e);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    return;
}

char a[500010];
ll sum[500010];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    vector <int> rev(n + 1);
    stack <int> stk;

    scanf(" %s", a);
    seq = a;
    scanf(" %s", a);
    mov = a;


    for (int i = 0; i < n; i++) {
        if (seq[i] == '(') {
            stk.push(i + 1);
        } else {
            int x = stk.top(); stk.pop();
            rev[i + 1] = x;
            rev[x] = i + 1;
        }
    }

    build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        lft[i] = i - 1;
        rht[i] = i + 1;
    }
    lft[1] = -1;
    rht[n] = -1;

    for (int i = 0; i < m; i++) {
        assert(p >= 1 && p <= n);
        if (mov[i] == 'L') {
            p = lft[p];
        } else if (mov[i] == 'R') {
            p = rht[p];
        } else {
            int a = p;
            int b = rev[p];
            if (a > b) swap(a, b);
            sum[a]++;
            sum[b + 1]--;
//            Delete(1, 1, n, a, b);

            if (rht[b] != -1) p = rht[b];
            else p = lft[a];

            int x = lft[a];
            int y = rht[b];

            rht[a] = y;
            lft[b] = x;

            if (x != -1) rht[x] = y;
            if (y != -1) lft[y] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i-1];
    }

//    gather(1, 1, n);
//    printf("%s\n", ans.c_str());
    for (int i = 1; i <= n; i++) {
        if (sum[i] == 0) {
            printf("%c", seq[i-1]);
        }
    }
    printf("\n");

    return 0;
}





