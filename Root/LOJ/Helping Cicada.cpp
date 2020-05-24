#include "stdio.h"

typedef long long ll;

template <class T> T GCD(T a,T b)
{
    if(b == 0) return a;
    return GCD(b,a%b);
}

template <class T> T LCM(T a,T b)
{
    return (a*b)/GCD(a,b);
}

ll n,m,var,ans[16],arr[16];

void bctk(ll in,ll ansin)
{
    if(in > n)
    {
        ll i,lc;
        if(ansin == 1) return;
        lc = ans[1];
        for(i=2;i<ansin;i++)
            lc = LCM(lc,ans[i]);
        if(ansin % 2 == 0) var += m/lc;
        else var -= m / lc;
        return;
    }
    ans[ansin] = arr[in];
    bctk(in+1,ansin+1);
    bctk(in+1,ansin);
}

int main()
{
    ll i,t,test;
    t = 0;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&m,&n);
        for(i=1;i<=n;i++) scanf("%lld",&arr[i]);
        var = 0;
        bctk(1,1);
        printf("Case %lld: %lld\n",++t,m-var);
    }
}
