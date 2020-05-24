#include "stdio.h"
#include "string.h"

#define SZ 100010
#define SZ1 262145
#define inf 1<<28

int min(int a,int b) { return a > b ? b : a; }

int input[SZ] , minim[SZ1];

void build(int node,int b,int e)
{
    if(b == e)
    {
        minim[node] = input[b];
        return;
    }
    int mid = (b + e) / 2;
    build(2*node,b,mid);
    build(2*node+1,mid+1,e);
    minim[node] = min( minim[2*node] , minim[2*node+1] );
}

int query(int node,int b,int e,int f,int t)
{
    if(b > t || e < f) return inf;
    if(b>=f && e<=t) return minim[node];
    int mid = (b + e) / 2;
    int a = query(2*node,b,mid,f,t);
    int c = query(2*node+1,mid+1,e,f,t);
    return min(a,c);
}

int main()
{
    int t,test,n,i,j,q;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++) scanf("%d",&input[i]);
        build(1,1,n);
        printf("Case %d:\n",++t);
        while(q--)
        {
            scanf("%d %d",&i,&j);
            printf("%d\n",query(1,1,n,i,j));
        }
    }
}
