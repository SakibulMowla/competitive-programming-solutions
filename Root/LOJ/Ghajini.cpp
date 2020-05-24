#define SZ1 100010
#define SZ2 3*100010

#include "stdio.h"
#include "string.h"

int max(int a,int b)
{
    return a > b ? a : b;
}

int min(int a,int b)
{
    return a < b ? a : b;
}

const int inf = 1e9;

int arr[SZ1];
struct data
{
    int max, min;
};
data tree[SZ2];

int maxim, minim;

void build(int b,int e,int node)
{
//    printf("%d %d %d\n",node, b, e);
    if(b == e)
    {
        tree[node].max = arr[b];
        tree[node].min = arr[b];
        return;
    }

    int mid = (b+e) >> 1 , left = node << 1, right = left + 1;

    build(b, mid, left);
    build(mid+1, e, right);

    tree[node].max = max(tree[left].max, tree[right].max);
    tree[node].min = min(tree[left].min, tree[right].min);
}

void query(int b, int e, int node, int f, int t)
{
//    printf("%d %d %d\n",node, b, e);
    if(b>=f && e<=t)
    {
        maxim = max(maxim, tree[node].max);
        minim = min(minim, tree[node].min);
        return;
    }

    int mid = (b+e) >> 1, left = node << 1, right = left + 1;

    if(f<=mid) query(b, mid, left, f, t);
    if(t > mid) query(mid+1, e, right, f, t);
}

int main()
{
//    freopen("1.txt","r",stdin);
    int t=0, test, n, d, i, j, ans;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d",&n,&d);
        for(i=1;i<=n;i++)   scanf("%d",&arr[i]);
        build(1, n, 1);

        ans = 0;

        for(i=1;i+d-1<=n;i++)
        {
            maxim = -inf;
            minim = inf;

            query(1, n, 1, i, i+d-1);
            ans = (maxim-minim) > ans ? (maxim-minim) : ans;
        }

        printf("Case %d: %d\n",++t,ans);
    }

    return 0;
}
