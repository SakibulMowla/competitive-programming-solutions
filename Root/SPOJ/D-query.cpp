#include "bits/stdc++.h"
using namespace std;

#define SZ 30010
#define SZ1 200010
#define SZ2 65540

#define left (node<<1), b, mid
#define riht (node<<1)|1, mid+1, e

inline void read (int &n)
{
    n = 0;
    int i = getchar_unlocked();

    while (i < '0' || i > '9')
        i = getchar_unlocked();

    while (i >= '0' && i <= '9')
    {
        n = (n << 3) + (n << 1) + i - '0';
        i = getchar_unlocked();
    }
}

struct data
{
    int l, r, num;
    char c;
};

int ans[SZ1];

data arr[SZ+SZ1];
int tree[SZ2];
int M[1000010];

bool comp(data p,data q)
{
    if(p.r == q.r)
        return p.c < q.c;
    return p.r < q.r;
}

void build(int node,int b,int e)
{
    tree[node] = 0;
    if(b == e) return;
    int mid = (b + e) >> 1;
    build(left);
    build(riht);
}

void update(int node,int b,int e,int pos,int val)
{
    if(b == e)
    {
        tree[node] = val;
        return;
    }
    int mid = (b + e) >> 1;
    if(pos <= mid) update(left, pos, val);
    else           update(riht, pos, val);
    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

int query(int node,int b,int e,int f,int t)
{
    if(b >= f && e <= t)
        return tree[node];
    int mid = (b + e) >> 1, sum = 0;
    if(f <= mid) sum += query(left, f, t);
    if(t > mid) sum += query(riht, f, t);
    return sum;
}

int main()
{
    int n, q, i, k;

    read(n);

    for(i=0;i<n;i++)
    {
        read(arr[i].l);
        arr[i].r = i+1;
        arr[i].c = '1';
    }

    read(q);
    k = 0;

    for(i=n;i<n+q;i++)
    {
        read(arr[i].l);read(arr[i].r);
        arr[i].c = '2';
        arr[i].num = k++;
    }

    sort(arr, arr+n+q, comp);
    build(1, 1, n);

    for(i=0;i<n+q;i++)
    {
        if(arr[i].c == '1')
        {
            if( !M[ arr[i].l ] )
            {
                update(1, 1, n, arr[i].r, 1);
                M[ arr[i].l ] = arr[i].r;
            }
            else
            {
                update(1, 1, n, M[ arr[i].l ], 0);
                update(1, 1, n, arr[i].r, 1);
                M[ arr[i].l ] = arr[i].r;
            }
        }
        else
        {
            ans[ arr[i].num ] = query(1, 1, n, arr[i].l, arr[i].r);
        }
    }

    for(i=0;i<q;i++)
        printf("%d\n",ans[i]);

    return 0;
}
