#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>
#include <time.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}

struct data {
	int L, R, i;
};

bool comp(data x, data y) {
	return x.R < y.R;
}

vector <data> v[320];

int a[SZ];
int Prev[SZ];
int Next[SZ];
int Last[SZ];
int ans[SZ];
int cnt[SZ];
int Left[SZ];
int Right[SZ];
int BLOCK;

int tree[4*SZ];

void Update (int node, int b, int e, int pos, int val) {
    if (b == e) {
        tree[node] = val;
        return;
    }
    int mid = (b + e) >> 1;
    if (pos <= mid) Update(node<<1, b, mid, pos, val);
    else Update((node<<1)|1, mid+1, e, pos, val);
    tree[node] = max(tree[node<<1], tree[(node<<1)|1]);
    return;
}

int M;

int dif[SZ];
set <int> ms;

inline void Add (int x) {
    dif[x]++;
    if (dif[x] == 1) ms.insert(x);
}

inline void Remove (int x) {
    dif[x]--;
    if (dif[x] == 0) ms.erase(ms.find(x));
}

inline void Add (int pos, bool f) { /// 0 means front, 1 means back
    int val = a[pos];
    cnt[val]++;
    if (cnt[val] == 1) {
        Left[val] = pos;
        Right[val] = pos;
//        Update(1, 1, M, val, 0);
        Add(Right[val] - Left[val]);
    } else {
        Remove(Right[val] - Left[val]);
        if (f) Right[val] = pos;
        else Left[val] = pos;
        Add(Right[val] - Left[val]);
//        Update(1, 1, M, val, Right[val] - Left[val]);
    }
    return;
}

inline void Remove (int pos, bool f) {
    int val = a[pos];
    cnt[val]--;
    if (cnt[val]) {
        Remove(Right[val] - Left[val]);
        if (f) Right[val] = Prev[pos];
        else Left[val] = Next[pos];
        Add(Right[val] - Left[val]);
//        Update(1, 1, M, val, Right[val] - Left[val]);
    } else {
//        Update(1, 1, M, val, 0);
        Remove(Right[val] - Left[val]);
        Right[val] = pos;
        Left[val] = pos;
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
//    inp(n);
//    inp(m);
//    inp(k);

    M = m;

    BLOCK = sqrt(n) + 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
//        inp(a[i]);
    }

    int tmp = max(n, m);

    for (int i = 0; i <= tmp; i++) {
        Prev[i] = -1;
        Next[i] = n;
        Last[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (~Last[ a[i] ]) {
            Prev[i] = Last[ a[i] ];
            Next[ Last[ a[i] ] ] = i;
        }
        Last[ a[i] ] = i;
    }

    int a, b;
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
//        inp(a);
//        inp(b);
        --a, --b;
        v[a/BLOCK].pb({a, b, i});
    }

    int currentL = 0, currentR = 0;

    for (int i = 0; i < 320; i++) {
        if (!sz(v[i])) continue;

        sort(v[i].begin(), v[i].end(), comp);

        int tmp = sz(v[i]);
        for (int j = 0; j < tmp; j++) {
            int L = v[i][j].L, R = v[i][j].R;
            while(currentL > L) {
                Add(currentL-1, 0);
                currentL--;
            }
            while(currentR <= R) {
                Add(currentR, 1);
                currentR++;
            }
            while(currentL < L) {
                Remove(currentL, 0);
                currentL++;
            }
            while(currentR > R+1) {
                Remove(currentR-1, 1);
                currentR--;
            }
//            ans[ v[i][j].i ] = tree[1];
            ans[ v[i][j].i ] = *prev(ms.end());
//            if (v[i][j].i == 0) {
//                printf("i = %d sz = %d\n", v[i][j].i, sz(ms));
//                for (auto it:ms) {
//                    printf("%d\n", it);
//                }
//                printf("-------------\n");
//            }
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}





