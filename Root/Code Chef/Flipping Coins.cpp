#include "stdio.h"
#define SZ 100010

int tree[3*SZ] , lazy[3*SZ];

void pushdown(int node,int r)
{
    lazy[node<<1] += lazy[node];
    lazy[(node<<1)+1] += lazy[node];
    tree[node<<1] = (r - (r>>1)) - tree[node<<1];
    tree[(node<<1)+1] = (r>>1) - tree[(node<<1)+1];
    lazy[node] = 0;
}

void build(int b,int e,int node)
{
//    printf("b = %d  e = %d\n",b,e);
    tree[node] = lazy[node] = 0;
    if(b == e) return;
    int mid = (b + e) >> 1;
    build(b,mid,node<<1);
    build(mid+1,e,(node<<1)+1);
}

void update(int b,int e,int node,int f,int t)
{
    if(f > e || b > t) return;
    if(b>=f && e<=t)
    {
        tree[node] = (e-b+1) - tree[node];
        lazy[node]++;
        return;
    }
    if(lazy[node] % 2) pushdown(node,e-b+1);
    int mid = (b + e) >> 1;
    update(b,mid,node<<1,f,t);
    update(mid+1,e,(node<<1)+1,f,t);
    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

int query(int b,int e,int node,int f,int t)
{
//    printf("b = %d  e = %d node = %d\n",b,e,node);
    if(f > e || b > t) return 0;
    if(b>=f && e<=t) return tree[node];
    if(lazy[node] % 2) pushdown(node,e-b+1);
    int mid = (b + e) >> 1;
    return query(b,mid,node<<1,f,t) + query(mid+1,e,(node<<1)+1,f,t);
}

int main()
{
//    freopen("1.txt","r",stdin);
    int n,q,i,j,k;
    while(2 == scanf("%d %d",&n,&q))
    {
        build(0,n-1,1);
        while(q--)
        {
            scanf("%d %d %d",&i,&j,&k);
            if(!i)
                update(0,n-1,1,j,k);
            else
                printf("%d\n",query(0,n-1,1,j,k));
        }
    }

    return 0;
}
