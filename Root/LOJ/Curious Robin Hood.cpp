#include "stdio.h"
#include "string.h"
#include "math.h"

#define SZ 262145

long long arr[100010] ,sum[SZ];


void build(long long node,long long b,long long e)
{
    if(b == e)
    {
        sum[node] = arr[b];
        return;
    }
    long long mid = (b + e) / 2;
    build(2*node,b,mid);
    build(2*node+1,mid+1,e);
    sum[node] = sum[2*node] + sum[2*node+1];
    return ;
}

void update(long long node,long long b,long long e,long long indx)
{
    if(b == e)
    {
        sum[node] = arr[b];
        return;
    }
    long long mid = (b + e) / 2;
    if(indx <= mid) update(2*node,b,mid,indx);
    else update(2*node+1,mid+1,e,indx);
    sum[node] = sum[2*node] + sum[2*node+1];
    return ;
}

long long query(long long node,long long b,long long e,long long f,long long t)
{
    if(f > e || t < b) return 0;
    if(f <= b && e <= t) return sum[node];
    long long sum1,sum2,mid;
    mid = (b+e) / 2;
    sum1 = query(2*node,b,mid,f,t);
    sum2 = query(2*node+1,mid+1,e,f,t);
    return sum1 + sum2;
}

int main()
{
    long long i,j,k,n,q,t,test=0;
//    freopen("1.txt","r",stdin);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        for(i=1; i<=n; i++) scanf("%lld",&arr[i]);
        build(1,1,n);
        printf("Case %lld:\n",++test);
        while(q--)
        {
            scanf("%lld",&i);
            if(i == 1)
            {
                scanf("%lld",&j);
                j++;
                printf("%lld\n",arr[j]);
                arr[j] = 0;
                update(1,1,n,j);
            }
            else if(i == 2)
            {
                scanf("%lld %lld",&j,&k);
                j++;
                arr[j] += k;
                update(1,1,n,j);
            }
            else if(i == 3)
            {
                scanf("%lld %lld",&j,&k);
                ++j;++k;
                printf("%lld\n",query(1,1,n,j,k));
            }
        }
    }

    return 0;
}
