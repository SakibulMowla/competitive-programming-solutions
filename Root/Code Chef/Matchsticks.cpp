using namespace std;

#include "stdio.h"
#include "string.h"
#include "iostream"

#define SZ 100010

typedef long long ll;
const ll inf = (1LL<<28);

template <class T> T maxim(T a,T b)
{
    return a > b ? a : b;
}

template <class T> T minim(T a,T b)
{
    return a < b ? a : b;
}

struct data
{
    ll small,large;
};

data tree[3LL*SZ];
ll burn[SZ];

void build(ll node,ll b,ll e)
{
//    printf("b = %lld e = %lld\n",b,e);
    if(b == e)
    {
        tree[node].large = burn[b];
        tree[node].small = burn[b];
        return ;
    }

    ll mid = (b + e) >> 1LL;

    build(node<<1LL , b , mid);
    build((node<<1LL) + 1LL , mid+1LL , e);

    tree[node].large = maxim( tree[ node<<1LL ].large , tree[ (node<<1LL) + 1LL ].large );
    tree[node].small = minim( tree[ node<<1LL ].small , tree[ (node<<1LL) + 1LL ].small );
}

ll big_query(ll node,ll b,ll e,ll st,ll end)
{
//    printf("st = %lld end = %lld\n",st,end);
    if(end < b || st > e || st > end) return -inf;

    if(b >= st && e <= end) return tree[node].large;

    ll ret = -inf , mid = (b + e) >> 1LL;

    if(mid >= st) ret = maxim(ret , big_query(node<<1LL , b , mid , st , end));
    if(mid < end) ret = maxim(ret , big_query( (node<<1LL) + 1LL , mid+1 , e , st , end ));

    return ret;
}

ll small_query(ll node,ll b,ll e,ll st,ll end)
{
    if(end < b || st > e || st > end) return inf;

    if(b >= st && e <= end) return tree[node].small;

    ll ret = inf , mid = (b + e) >> 1LL;

    if(mid >= st) ret = minim(ret , small_query(node<<1LL , b , mid , st , end));
    if(mid < end) ret = minim(ret , small_query( (node<<1LL) + 1LL , mid+1 , e , st , end ));

    return ret;
}

int main()
{
    ll i,j,n,m,k,besi,kom;
    double d;

    while(scanf("%lld",&n) == 1)
    {

        for(i=1; i<=n; i++)    scanf("%lld",&burn[i]);

        build(1LL , 1LL , n);

        scanf("%lld",&m);

        while(m--)
        {
            scanf("%lld %lld",&j,&k);

            besi = 0;
            j++ , k++;

            kom = small_query(1LL , 1 , n , j , k);
            besi = big_query(1LL , 1 , n , j , k) - kom;

            d = besi / 2. ;
            besi = maxim(big_query(1LL , 1LL , n , 1LL , j-1LL) , big_query(1LL , 1LL , n , k+1LL , n));
            d = maxim(d , (double)besi );
            d += kom;

            printf("%.1lf\n",d);
        }

    }

    return 0;
}
