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

#define SZ 100010

int tree[4*SZ];
int arr[SZ];

void build (int node, int b, int e) {
    if (b == e) {
        tree[node] = arr[b];
    } else {
        int mid = (b + e) >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    return;
}

void update (int node, int b, int e, int pos) {
    if (b == e) {
        tree[node] = arr[b];
    } else {
        int mid = (b + e) >> 1;
        if (pos <= mid) update(2 * node, b, mid, pos);
        else update(2 * node + 1, mid + 1, e, pos);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    return;
}

int query (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) {
        return tree[node];
    } else {
        int mid = (b + e) >> 1;
        int ret = numeric_limits <int> :: max();
        if (f <= mid) ret = query(2 * node, b, mid, f, t);
        if (t > mid) ret = min(ret, query(2 * node + 1, mid + 1, e, f, t));
        return ret;
    }
}

char s[32], *ptr;
int tmp[32];

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        scanf("%s", s);
        int type = s[0] == 'q';
        ptr = strtok(s, "(),queryshift");
        int idx = 0;
        while (ptr != NULL) {
            tmp[idx++] = atoi(ptr);
            ptr = strtok(NULL, "(),");
        }
        if (type) {
            printf("%d\n", query(1, 1, n, tmp[0], tmp[1]));
        } else {
            int save = arr[tmp[0]];
            for (int j = 0; j < idx - 1; j++) {
                arr[tmp[j]] = arr[tmp[j+1]];
                update(1, 1, n, tmp[j]);
            }
            arr[tmp[idx-1]] = save;
            update(1, 1, n, tmp[idx-1]);
        }
    }


    return 0;
}







