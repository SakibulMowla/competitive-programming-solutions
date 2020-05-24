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

#define SZ 200000+10
#define SZ1 1000010
int BLOCK;

int cnt[SZ1];
int a[SZ];
ll ans[SZ];

struct data {
    int L, R, idx;
};
data q[SZ];

bool comp (data a, data b) {
    if (a.L/BLOCK != b.L/BLOCK) {
        return a.L/BLOCK < b.L/BLOCK;
    }
    return a.R < b.R;
}

ll sum;

void Add (int pos) {
    sum += (ll)a[pos] * (2LL * (ll)cnt[a[pos]] + 1LL);
    cnt[a[pos]]++;
}

void Remove (int pos) {
    sum += (ll)a[pos] * (1LL - 2LL * (ll)cnt[a[pos]]);
    cnt[a[pos]]--;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    int n, m;
    scanf("%d %d", &n, &m);

    BLOCK = sqrt(n) + 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &q[i].L, &q[i].R);
        q[i].L--;
        q[i].R--;
        q[i].idx = i;
    }

    sort(q, q+m, comp);

    int curL = 0, curR = 0;
    sum = 0;

    for (int i = 0; i < m; i++) {
        int L = q[i].L;
        int R = q[i].R;

        while (curL < L) {
            Remove(curL);
            curL++;
        }
        while (curL > L) {
            Add(curL-1);
            curL--;
        }
        while (curR <= R) {
            Add(curR);
            curR++;
        }
        while (curR > R+1) {
            Remove(curR-1);
            curR--;
        }
        ans[q[i].idx] = sum;
    }

    for (int i = 0; i < m; i++) {
        printf("%I64d\n", ans[i]);
    }


    return 0;
}







