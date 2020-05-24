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

//#include <bits/stdc++.h>

using namespace  std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)

template <class T> inline T gcd(T a, T b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}
const int inf = 1e9;

inline int FastMax(long x, long y) {
    return (((y-x)>>(32-1))&(x^y))^y;
}
inline int FastMin(long x, long y) {
    return (((y-x)>>(32-1))&(x^y))^x;
}

#define SZ  3*100010
#define SZ1 4*3*100010

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

struct data {
    int _gcd, _min;
};

data tree[SZ1];
data u;
int arr[SZ];

inline void build(int node, int b, int e) {
    if(b == e) {
        tree[node]._gcd = tree[node]._min = arr[b];
        return;
    }
    int mid = (b+e) >> 1;
    build(left);
    build(riht);
    tree[node]._gcd = gcd(tree[node<<1]._gcd, tree[(node<<1)|1]._gcd);
    tree[node]._min = FastMin(tree[node<<1]._min, tree[(node<<1)|1]._min);
}

inline void query(int node, int b, int e, int f, int t) {
    if(b>=f && e<=t) {
        u._gcd = gcd(u._gcd, tree[node]._gcd);
        u._min = FastMin(u._min, tree[node]._min);
        return;
    }
    int mid = (b+e) >> 1;
    if(f <= mid) query(left, f, t);
    if(t > mid) query(riht, f, t);
}

inline bool ok(int range, int n) {
    int i;

    for(i=1; i+range<=n; i++) {
        u._min = inf;
        u._gcd = 0;
        query(1, 1, n, i, i+range);
        if(u._gcd == u._min) return true;
    }

    return false;
}

int ans[SZ];

int main() {
    int i, n, lo, hi, mid, range, k;

    while(scanf("%d",&n) == 1) {
        REP1(i, 1, n) scanf("%d",&arr[i]);

        build(1, 1, n);

        lo = range = 0;
        hi = n-1;

        while(lo <= hi) {
            mid = (lo+hi) >> 1;
            if(ok(mid, n))
                range = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }

        k = 0;

        for(i=1; i+range<=n; i++) {
            u._min = inf;
            u._gcd = 0;
            query(1, 1, n, i, i+range);
            if(u._gcd == u._min)
                ans[k++] = i;
        }

        printf("%d %d\n",k,range);
        REP(i, k) printf("%d ",ans[i]);
        puts("");
    }


    return 0;
}
















