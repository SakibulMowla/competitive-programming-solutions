#include "stdio.h"
#define SZ 30010
#define SZ1 65540

int min(int a,int b)
{
    return a < b ? a : b;
}

struct data
{
    int sum, minim;
};

int arr[SZ];
data tree[SZ1];

void build(int b,int e,int node)
{
    if(b == e)
    {
        tree[node].minim = tree[node].sum = arr[b];
        return;
    }

    int mid = (b+e) >> 1, left = node << 1, right = left + 1;

    build(b, mid, left);
    build(mid+1, e, right);

    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].minim = min(tree[left].minim, tree[left].sum + tree[right].minim);
}

void update(int b,int e,int node,int indx)
{
    if(b == e)
    {
        tree[node].minim = tree[node].sum = arr[b];
        return;
    }

    int mid = (b+e) >> 1, left = node << 1, right = left + 1;

    if(indx <= mid) update(b, mid, left, indx);
    else update(mid+1, e, right, indx);

    tree[node].sum = tree[left].sum + tree[right].sum;
    tree[node].minim = min(tree[left].minim, tree[left].sum + tree[right].minim);
}

char s[SZ];

int main()
{
    int ten, n, m, i;
    data ans;

    for(ten=1;ten<=10;ten++)
    {
        scanf("%d %s %d",&n,s+1,&m);

        for(i=1;i<=n;i++)arr[i] = (s[i] == '(') ? 1 : -1;
        build(1, n, 1);

        printf("Test %d:\n",ten);

        while(m--)
        {
            scanf("%d",&i);
            if(i)
            {
                arr[i] *= -1;
                update(1, n, 1, i);
            }
            else
            {
                if(tree[1].sum == 0 && tree[1].minim == 0) printf("YES\n");
                else printf("NO\n");
            }
        }
    }

    return 0;
}
