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

#define X First
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

struct data {
    int l, r, indx;
};

vector <data> arr[320];

int BLOCK;

bool comp (data a, data b) {
    if (a.l/BLOCK != b.l/BLOCK) {
        return a.l/BLOCK < b.l/BLOCK;
    }
    return a.r < b.r;
}

int a[SZ];
int cnt[SZ];
int ans[SZ];
int now;
int aseq;

int Prev[SZ];
int Next[SZ];
int First[SZ];
int Last[SZ];
int Par[SZ];
bool Flag[SZ];

void Add (int pos, int dir) { /// dir 0 means front and 1 means back
    cnt[ a[pos] ]++;
    if (cnt[ a[pos] ] == 1) {
        now++;
        First[ a[pos] ] = Last[ a[pos] ] = pos;
        Flag[ a[pos] ] = true;
        aseq++;
    } else {
        if (dir == 0) First[ a[pos] ] = pos;
        else Last[ a[pos] ] = pos;
        aseq -= Flag[a[pos]];
        Flag[a[pos]] = false;
        if (Par[ Last[ a[pos] ] ] <= First[ a[pos] ]) {
            Flag[ a[pos] ] = true;
            aseq++;
        }
    }
}

void Remove (int pos, int dir) {
    cnt[ a[pos] ]--;
    if (cnt[ a[pos] ] == 0) {
        now--;
        Flag[ a[pos] ] = false;
        aseq--;
    } else {
        if (dir == 0) First[ a[pos] ] = Next[pos];
        else Last[ a[pos] ] = Prev[pos];
        aseq -= Flag[a[pos]];
        Flag[a[pos]] = false;
        if (Par[ Last[ a[pos] ] ] <= First[ a[pos] ]) {
            Flag[ a[pos] ] = true;
            aseq++;
        }
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);

    BLOCK = sqrt(n) + 1;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        int tmp = Last[ a[i] ];
        Prev[i] = tmp;
        Next[tmp] = i;
        if (tmp == 0) Par[i] = i;
        else if (Prev[tmp] == 0) Par[i] = tmp;
        else {
            if (i-tmp == tmp-Prev[tmp]) Par[i] = Par[Prev[i]];
            else Par[i] = Prev[i];
        }
        Last[ a[i] ] = i;
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        data d;
        scanf("%d %d", &d.l, &d.r);
        d.indx = i;
        arr[d.l/BLOCK].pb(d);
    }

    now = 0;
    aseq = 0;
    int curL = 1, curR = 1;

    for (int i = 0; i < 320; i++) {
        if (!sz(arr[i])) continue;

        sort(arr[i].begin(), arr[i].end(), comp);

        for (int j = 0; j < sz(arr[i]); j++) {
            int L = arr[i][j].l;
            int R = arr[i][j].r;

            while (curL > L) {
                Add(curL-1, 0);
                curL--;
            }
            while (curR <= R) {
                Add(curR, 1);
                curR++;
            }
            while (curL < L) {
                Remove(curL, 0);
                curL++;
            }
            while (curR > R + 1) {
                Remove(curR-1, 1);
                curR--;
            }

            ans[ arr[i][j].indx ] = now + (aseq == 0);
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }


    return 0;
}






