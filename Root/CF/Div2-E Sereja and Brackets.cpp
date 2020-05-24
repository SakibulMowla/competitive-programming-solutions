#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define left (node<<1), b, mid
#define riht (node<<1)|1, mid+1, e

#define SZ  1000010
#define SZ1 4*1000010

struct data{
    int sum, lft, rht;
};

data x;
data tree[SZ1];
char arr[SZ];

data join(data &a, data &b){
    data c;
    int mn;

    mn = min(a.lft, b.rht);
    c.sum = a.sum + b.sum + 2*mn;
    c.lft = a.lft + b.lft - mn;
    c.rht = a.rht + b.rht - mn;

    return c;
}

void build(int node, int b, int e){
    if(b == e){
        tree[node].sum = 0;
        tree[node].lft = (arr[b]=='(');
        tree[node].rht = (arr[b]==')');
        return;
    }

    int mid = (b+e) >> 1;

    build(left);
    build(riht);

    tree[node] = join(tree[node<<1], tree[(node<<1)|1]);
}

data query(int node, int b, int e, int f, int t){
    if(b>=f && e<=t) return tree[node];

    int mid = (b+e) >> 1;

    data chld1, chld2;
    chld1 = chld2 = x;

    if(f <= mid) chld1 = query(left, f, t);
    if(t > mid) chld2 = query(riht, f, t);

    return join(chld1, chld2);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    x.lft = x.rht = x.sum = 0;
    int n, m, i, j;

    scanf("%s",arr+1);
    n = strlen(arr+1);

    build(1, 1, n);

    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&i,&j);
        printf("%d\n",query(1, 1, n, i, j).sum);
    }


    return 0;
}
















