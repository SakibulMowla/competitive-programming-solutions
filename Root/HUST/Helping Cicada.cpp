#include "stdio.h"
typedef long long ll;
#define SZ 20

template <class T> T GCD(T a,T b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}

template <class T> T LCM(T a,T b)
{
    return (a*b)/GCD(a,b);
}

ll arr[SZ] , ans[SZ] , n , m ,val;

void subset(ll indx,ll ansin)
{
    if(indx > m)
    {
        if(ansin <= 1) return;
        ll i,k;
        k = ans[1];
        for(i=2;i<ansin;i++)
            k = LCM(k,ans[i]);
        if(ansin % 2 == 0) val += n / k;
        else val -= n / k;
        return;
    }
    ans[ansin] = arr[indx];
    subset(indx+1,ansin+1);
    subset(indx+1,ansin);
}

int main()
{
    ll i,t,test;
    t = 0;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=m;i++) scanf("%lld",&arr[i]);
        val = 0;
        subset(1,1);
        printf("Case %lld: %lld\n",++t,n-val);
    }

    return 0;
}
