#include "stdio.h"
#include "iostream"
#include "map"
#include "algorithm"

using namespace std;

typedef long long ll;
#define SZ 30010
#define SZ1 65540
#define SZ2 100010

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

struct data
{
    int b, e, indx;
    char m;
};

data info[SZ2+SZ];

bool comp(data p,data q)
{
    if(p.e == q.e) return p.m < q.m;
    return p.e < q.e;
}

int arr[SZ];
ll tree[SZ1];

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
    else update(riht, pos, val);

    tree[node] = tree[node<<1] + tree[(node<<1)|1];
}

ll query(int node,int b,int e,int f,int t)
{
    if(b >= f && e <= t)
        return tree[node];

    int mid = (b + e) >> 1;
    ll ret = 0;

    if(f <= mid) ret = query(left, f, t);
    if(t > mid) ret += query(riht, f, t);

    return ret;
}

map <int , int> M;
ll ans[SZ2];

int main()
{
    int t, i, n, q;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
            info[i].b = arr[i];
            info[i].e = i;
            info[i].m = '0';
        }

        build(1, 1, n);
        M.clear();

        scanf("%d",&q);

        for(;i<=n+q;i++)
        {
            scanf("%d %d",&info[i].b,&info[i].e);
            info[i].m = '1';
            info[i].indx = i - n;
        }

        sort(info+1, info+n+q+1, comp);

//        printf("yes\n");

//        for(i=1;i<=n+q;i++)
//            printf("%c %d %d\n",info[i].m,info[i].b,info[i].e);

        for(i=1;i<=n+q;i++)
        {
            if(info[i].m == '0')
            {
                update(1, 1, n, info[i].e, info[i].b);
                if(M.find(info[i].b) != M.end())
                    update(1, 1, n, M[info[i].b], 0);
                M[ info[i].b ] = info[i].e;
            }
            else
            {
                ans[info[i].indx] = query(1, 1, n, info[i].b, info[i].e);
            }
        }

        for(i=1;i<=q;i++)
            printf("%I64d\n",ans[i]);
    }

    return 0;
}
