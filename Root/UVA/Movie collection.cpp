#include "stdio.h"

#define SZ  100010
#define SZ1 200010
#define SZ2 524290

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1,e

#define read freopen("1.txt", "r", stdin);

int tree[SZ2];
int pos[SZ1];
int n;

void push_up(int node)
{
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
}

void build(int node, int b, int e)
{
    if(b == e)
    {
        if(b <= n)
            tree[node] = 1;
        else
            tree[node] = 0;
        return;
    }

    int mid= (b + e) >> 1;

    build(left);
    build(riht);

    push_up(node);
}


int query(int node, int b, int e, int f, int t)
{
    if(b >= f && e <= t)
        return tree[node];

    int mid = (b + e) >> 1, sum = 0;

    if(f <= mid)
        sum = query(left, f, t);
    if(t > mid)
        sum += query(riht, f, t);

    return sum;
}

void update(int node, int b, int e, int x)
{
    if(b == e)
    {
        tree[node] = !tree[node];
        return;
    }

    int mid = (b + e) >> 1;

    if(x <= mid)
        update(left, x);
    else
        update(riht, x);

    push_up(node);
}

int main()
{
//    read;
    int t, q, i, j;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&q);

        build(1, 1, n+q);

        for(i=1;i<=n;i++)
            pos[i] = n-i+1;

        for(i=0;i<q;i++)
        {
            scanf("%d",&j);

            if(i) printf(" ");

            printf("%d",query(1, 1, n+q, pos[j]+1, n+q));

            update(1, 1, n+q, pos[j]);
            pos[j] = n + i + 1;
            update(1, 1, n+q, pos[j]);
        }

        printf("\n");

    }

    return 0;
}
