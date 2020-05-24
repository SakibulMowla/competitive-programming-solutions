#include <bits/stdc++.h>

using namespace  std;
typedef long long ll;
const ll inf = 1LL<<28;

#define SZ 300010
#define SZ1 1050000

int arr[SZ], pos[SZ];

struct data
{
    int fast, last, cnt;
};

data tree[SZ1];
data ans;

data prop(data &a,data &b)
{
    data ret;

    ret.fast = a.fast;
    ret.last = b.last;
    ret.cnt = a.cnt + b.cnt;

    if(a.last < b.fast)
        ret.cnt--;

    return ret;
}

void build(int node,int b,int e)
{
    if(b == e)
    {
        tree[node].fast = tree[node].last = pos[ b ];
        tree[node].cnt = 1;
        return;
    }

    int mid = (b + e) / 2;

    build(2*node, b, mid);
    build((2*node)+1, mid+1, e);

    tree[node] = prop( tree[2*node], tree[(2*node) + 1] );
}

void update(int node,int b,int e,int x)
{
    if(x < b || x > e) return;
    if(b == e)
    {
        tree[node].fast = tree[node].last = pos[b];
        tree[node].cnt = 1;
        return;
    }

    int mid = (b + e) / 2;

    update(2*node, b, mid, x);
    update((2*node)+1, mid+1, e, x);

    tree[node] = prop(tree[2*node], tree[(2*node)+1]);
}

void query(int node,int b,int e,int f,int t)
{
    if(b > t || e < f)
        return;
    if(b >= f && e <= t)
    {
        ans = prop(ans, tree[node]);
        return;
    }

    int mid = (b + e) / 2;

    query(2*node, b, mid, f, t);
    query((2*node)+1, mid+1, e, f, t);
}

int main()
{
    int n, m, i, j, k;

    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
        pos[ arr[i] ] = i;
    }

    build(1, 1, n);

    scanf("%d",&m);

    while(m--)
    {
        scanf("%d %d %d",&k,&i,&j);
        if(k == 1)
        {
            ans.fast = 0;
            ans.last = inf;
            ans.cnt = 0;

            query(1, 1, n, i, j);

            printf("%d\n",ans.cnt);
        }
        else
        {
            swap(pos[arr[i]], pos[arr[j]]);
            swap(arr[i], arr[j]);

            update(1, 1, n, arr[i]);
            update(1, 1, n, arr[j]);
        }
    }

    return 0;
}
