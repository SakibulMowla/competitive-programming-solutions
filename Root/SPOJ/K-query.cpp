#include "bits/stdc++.h"
using namespace std;

#define SZ 30010
#define SZ1 65540

#define left node<<1, b, mid
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
    int i, j, v, num;
    char c;
};

data arr[230010];

bool comp(data p,data q)
{
    if(p.v == q.v)
        return p.c > q.c;
    return p.v > q.v;
}

int tree[SZ1];
int ans[200010];

void update(int node,int b,int e,int pos)
{
    if(b == e)
    {
        tree[node] = 1;
        return;
    }
    int mid = (b + e) >> 1;
    if(pos <= mid) update(left, pos);
    else update(riht, pos);
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
}

int query(int node,int b,int e,int f,int t)
{
    if(b >= f && e <= t)
        return tree[node];
    int mid = (b + e) >> 1, sum = 0;
    if(f <= mid) sum = query(left, f, t);
    if(t > mid) sum += query(riht, f, t);
    return sum;
}

int main()
{
    int i, j, k, n, q;

    read(n);

    for(i=0; i<n; i++)
    {
        read(arr[i].v);
        arr[i].j = i+1;
        arr[i].c = '1';
    }

    read(q);

    j = 0;

    for(k=0;k<q;k++)
    {
        read(arr[i].i);
        read(arr[i].j);
        read(arr[i].v);
        arr[i].num = j++;
        arr[i].c = '2';
        i++;
    }

    sort(arr, arr+n+q, comp);

    for(i=0; i<n+q; i++)
    {
        if(arr[i].c == '1')
        {
            update(1, 1, n, arr[i].j);
        }
        else
        {
            ans[ arr[i].num ] = query(1, 1, n, arr[i].i, arr[i].j);
        }
    }

    for(i=0; i<q; i++)
        printf("%d\n",ans[i]);

    return 0;
}
