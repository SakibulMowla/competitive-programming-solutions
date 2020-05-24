#include "bits/stdc++.h"
using namespace std;

#define SZ 150010
#define SZ1 524290

#define left (node<<1), b, mid
#define riht (node<<1)|1, mid+1, e

int arr[SZ];
int tree[SZ1];
int tot, n;

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

void build(int node,int b,int e)
{
    if(b == e)
    {
        if(b <= n) tree[node] = 1;
        else tree[node] = 0;
        return;
    }
    int mid = (b + e) >> 1;
    build(left);
    build(riht);
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
}

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

int query(int node,int b,int e,int num)
{
    if(b == e)
    {
        tree[node]--;
        return arr[b];
    }
    int mid = (b + e) >> 1, x;
    if(tree[node<<1] >= num) x = query(left, num);
    else x = query(riht, num-tree[node<<1]);
    tree[node] = tree[node<<1] + tree[(node<<1)|1];
    return x;
}

int main()
{
    int test=0, t, i, q;
    char c;

    scanf("%d",&t);
    while(t--)
    {
        read(n);
        read(q);
        tot = n + q;
        build(1, 1, tot);
        for(i=1;i<=n;i++)
            read(arr[i]);
        printf("Case %d:\n",++test);
        while(q--)
        {
            scanf(" %c",&c);
            read(i);
            if(c == 'a')
            {
                arr[++n] = i;
                update(1, 1, tot, n);
            }
            else
            {
                if(tree[1] < i) printf("none\n");
                else printf("%d\n",query(1, 1, tot, i));
            }
        }
    }

    return 0;
}
