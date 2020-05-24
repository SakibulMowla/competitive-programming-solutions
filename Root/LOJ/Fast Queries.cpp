#include "bits/stdc++.h"
using namespace std;

#define SZ 400010
#define SZ1 400010
#define SZ2 400010

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e


struct data
{
    int l, r, num;
    char c;
};

data arr[SZ+SZ1];
int tree[SZ2];
int M[100010];
int ans[SZ1];

bool comp(data p,data q)
{
    if(p.r == q.r) return p.c < q.c;
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

void update(int node,int b,int e,int x,int val)
{
    if(b == e)
    {
        tree[node] = val;
        return;
    }
    int mid = (b + e) >> 1;
    if(x <= mid) update(left, x, val);
    else update(riht, x, val);
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
    int t=0, test, i, j, n, q;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d", &n);
        scanf("%d", &q);

        for(i=0;i<n;i++)
        {
            scanf("%d", &arr[i].l);
            arr[i].r = i+1;
            arr[i].c = '1';
        }

        j = 0;

        for(i=n;i<n+q;i++)
        {
            scanf("%d", &arr[i].l);
            scanf("%d", &arr[i].r);
            arr[i].c = '2';
            arr[i].num = j++;
        }

        sort(arr, arr+n+q, comp);
        memset(M, 0, sizeof(M));

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
                ans[arr[i].num] = query(1, 1, n, arr[i].l, arr[i].r);
            }
        }

        printf("Case %d:\n",++t);
        for(i=0;i<q;i++)
            printf("%d\n",ans[i]);
    }

    return 0;
}


