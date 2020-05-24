#include  "stdio.h"
#include  "string.h"

#define SZ1 100010
#define SZ2 400010 // 2^(1+ceil(lg(n)))

struct data
{
    int zero, one, two;
};

data tree[SZ2];

int lazy[SZ2];

void change(int node)
{
    int a = tree[node].two;
    tree[node].two = tree[node].one;
    tree[node].one = tree[node].zero;
    tree[node].zero = a;
}

void propagate(int node)
{
    int left = node << 1, right = left+1;

    lazy[left] = (lazy[left] + lazy[node]) % 3;
    lazy[right] = (lazy[right] + lazy[node]) % 3;

    if(lazy[node])
    {
        change(left);
        change(right);
        if(lazy[node] == 2) change(left),change(right);
    }

    lazy[node] = 0;
}

void summation(int node,int left,int right)
{
    tree[node].zero = tree[left].zero + tree[right].zero;
    tree[node].one = tree[left].one + tree[right].one;
    tree[node].two = tree[left].two + tree[right].two;
}

void build(int b,int e,int node)
{
    if(b == e)
    {
        tree[node].zero = 1;
        tree[node].one = tree[node].two = 0;
        lazy[node] = 0;
        return;
    }

    int mid = (b+e) >> 1, left = node << 1, right = left+1;

    build(b, mid, left);
    build(mid+1, e, right);

    lazy[node] = 0;
    summation(node, left, right);
}

void update(int b, int e, int node, int f, int t)
{
    if(b>=f && e<=t)
    {
        lazy[node] = (lazy[node]+1) % 3;
        change(node);
        return;
    }

    int mid = (b+e) >> 1, left = node << 1, right = left+1;

    propagate(node);

    if(f <= mid) update(b, mid, left, f, t);
    if(t > mid) update(mid+1, e, right, f, t);

    summation(node, left, right);
}

int query(int b, int e, int node, int f, int t)
{
    if(b >= f && e <= t)
        return tree[node].zero;

    int mid = (b+e) >> 1, left = node << 1, right = left+1, sum = 0;

    propagate(node);

    if(f <= mid) sum += query(b, mid, left, f, t);
    if(t > mid) sum += query(mid+1, e, right, f, t);

    return sum;
}

int main()
{
//    freopen("1.txt","r",stdin);
    int t=0, test, n, m, q, i, j;

    scanf("%d %d",&n,&q);

    build(1, n, 1);

    while(q--)
    {
        scanf("%d %d %d",&m,&i,&j);
        i++, j++;

        if(m == 0)  update(1, n, 1, i, j);
        else        printf("%d\n",query(1, n, 1, i, j));
    }

    return 0;
}
