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

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1e16;
const ll mod = 1LL;

#define SZ  500010
#define SZ1 1048580

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

ll arr[SZ];
ll tree[SZ1];
ll need;
ll found;
int indx;

void build(int node, int b, int e){
    if(b == e){
        tree[node] = arr[b];
        return;
    }
    int mid = (b+e) >> 1;
    build(left);
    build(riht);
    tree[node] = max(tree[node<<1], tree[(node<<1)|1]);
}

void query(int node, int b, int e){
    if(b == e){
        if(tree[node] >= need){
            found = tree[node];
            indx = b;
        }
        return;
    }
    int mid = (b+e) >> 1;
    if(tree[node<<1] >= need) query(left);
    else if(tree[(node<<1)|1] >= need) query(riht);
}

void update(int node, int b, int e, int pos){
    if(b == e){
        tree[node] = -inf;
        return;
    }
    int mid = (b+e) >> 1;
    if(pos <= mid) update(left, pos);
    else update(riht, pos);
    tree[node] = max(tree[node<<1], tree[(node<<1)|1]);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t, n, x, i, j, ans;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&x);
        REP1(i, 1, n){
            scanf("%d",&j);
            arr[i] = j + arr[i-1];
        }
        build(1, 1, n);
        ans = 500010;
        REP1(i, 1, n){
            need = x + arr[i-1];
            found = -inf;
            query(1, 1, n);
            if(found >= need){
                ans = min(ans, indx-i+1);
            }
            update(1, 1, n, i);
        }
        ans == 500010 ? printf("-1\n") : printf("%d\n",ans);
    }


    return 0;
}














