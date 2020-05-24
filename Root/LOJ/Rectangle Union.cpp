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

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a))

typedef pair<int , int> pii;

#define SZ 30010

/// For Segemnt Tree
int tree[8*SZ], cnt[8*SZ];

/// For Praparation
struct data{
    int x1, y1, x2, y2;
};
data arr[SZ];

int x_axis[2*SZ], y_axis[2*SZ];
int xcnt, ycnt;
vector <pii> ins[2*SZ], del[2*SZ];

void Update(int node, int b, int e, int f, int t, int val) { /// node, begin, end, from, to, value = +1 or, -1
    if(b >= t || e <= f) return;
    if(b >= f && e <= t) {
        cnt[node] += val;
        if(cnt[node])
            tree[node] = y_axis[e] - y_axis[b];
        else {
            if(b + 1 == e) tree[node] = 0;
            else tree[node] = tree[2*node] + tree[2*node+1];
        }
        return;
    }

    int mid = (b + e) >> 1;

    Update(2*node, b, mid, f, t, val);
    Update(2*node+1, mid, e, f, t, val);

    if(cnt[node] == 0) tree[node] = tree[2*node] + tree[2*node+1];
    else tree[node] = y_axis[e] - y_axis[b];

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    int test=0, t, i, j, k, n;
    ll ans;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);

        for(i = 0; i <= 2*n; i++) {
            ins[i].clear();
            del[i].clear();
        }

        xcnt = ycnt = 0;
        for(i = 0; i < n; i++) {
            scanf("%d %d %d %d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
            x_axis[xcnt++] = arr[i].x1;
            x_axis[xcnt++] = arr[i].x2;
            y_axis[ycnt++] = arr[i].y1;
            y_axis[ycnt++] = arr[i].y2;
        }

        sort(x_axis, x_axis+xcnt);
        sort(y_axis, y_axis+ycnt);

        xcnt = unique(x_axis, x_axis+xcnt) - x_axis;
        ycnt = unique(y_axis, y_axis+ycnt) - y_axis;

        for(i = 0; i < n; i++) {
            arr[i].x1 = lower_bound(x_axis, x_axis+xcnt, arr[i].x1) - x_axis;
            arr[i].x2 = lower_bound(x_axis, x_axis+xcnt, arr[i].x2) - x_axis;
            arr[i].y1 = lower_bound(y_axis, y_axis+ycnt, arr[i].y1) - y_axis;
            arr[i].y2 = lower_bound(y_axis, y_axis+ycnt, arr[i].y2) - y_axis;

            ins[ arr[i].x1 ].pb( MP(arr[i].y1, arr[i].y2) );
            del[ arr[i].x2 ].pb( MP(arr[i].y1, arr[i].y2) );
        }

        mem(tree, 0);
        mem(cnt, 0);
        ans = 0LL;

        for(i = 0; i < xcnt; i++) {
            if(i) ans += (ll)( x_axis[i] - x_axis[i-1] ) * (ll) tree[1];

            k = sz(ins[i]);
            for(j = 0; j < k; j++) {
                Update(1, 0, ycnt-1, ins[i][j].first, ins[i][j].second, 1);
            }

            k = sz(del[i]);
            for(j = 0; j < k; j++) {
                Update(1, 0, ycnt-1, del[i][j].first, del[i][j].second, -1);
            }
        }

        printf("Case %d: %lld\n", ++test, ans);
    }

    return 0;
}












