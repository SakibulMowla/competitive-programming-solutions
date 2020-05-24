#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ  1000010
#define SZ1 4*SZ

#define left node<<1, l, mid
#define riht (node<<1)|1, mid+1, r

ll arr[SZ];
ll tree[SZ1];

void push_up(int node) {
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
}

void build(int node, int l, int r) {
    if(l == r) {
        tree[node] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;

    build(left);
    build(riht);

    push_up(node);
}

void update(int node, int l, int r, int pos) {
    if(l == r) {
        tree[node] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;

    if(pos <= mid) update(left, pos);
    else update(riht, pos);

    push_up(node);
}

ll query(int node, int l, int r, int f, int t) {
    if(l >= f && r <= t)
        return tree[node];

    int mid = (l + r) >> 1;
    ll ret = 0;

    if(f <= mid) ret = query(left, f, t);
    if(t > mid) ret += query(riht, f, t);

    return ret;
}

int main() {
    int n, q, i, j;
    char ch;

    while(scanf("%d %d",&n,&q) == 2) {

        REP(i, n) scanf("%lld",&arr[i+1]);


        build(1, 1, n);

        while(q--) {
            scanf(" %c",&ch);
            scanf("%d %d",&i,&j);

            i++;
            if(ch == 'G' || ch == 'T') {
                if(ch == 'G') arr[i] += j;
                if(ch == 'T') arr[i] -= j;
                update(1, 1, n, i);
            } else {
                j++;
                printf("%lld\n",query(1, 1, n, i, j));
            }

        }
    }


    return 0;
}

















