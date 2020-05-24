
#include "bits/stdc++.h"
using namespace std;

#define SZ 20
typedef long long ll;

template <class T> T LCM(T a,T b)
{
    return (a*b)/__gcd(a,b);
}

ll arr[SZ];


int main()
{
    ll n, m, i, k, lim, g;

    while(scanf("%lld %lld",&n,&m) == 2)
    {
        for(i=0;i<m;i++)
            scanf("%lld",&arr[i]);

        lim = 1<<m;
        k = n;

        while(lim--)
        {
            g = 1;

            for(i=0;i<m;i++)
                if(lim&(1<<i))
                    g = LCM(g, arr[i]);
//            printf("lim = %lld g = %lld\n",lim,g);
            if(__builtin_popcount(lim) > 0)
            {
                if(__builtin_popcount(lim)%2 == 1)
                    k = k - (n / g);
                else
                    k = k + (n / g);
            }
        }

        printf("%lld\n",k);
    }

    return 0;
}
