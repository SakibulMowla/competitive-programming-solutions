#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define SZ 100010

ll arr[SZ];
ll cnt[40];


int main()
{
    ll n, i, j, res, two;

    scanf("%lld",&n);

    for(i=0; i<n; i++)
        scanf("%lld",&arr[i]);

    for(i=0; i<n; i++)
    {
        for(j=0; j<31; j++)
        {
            if(arr[i] & (1LL<<j))
            {
                cnt[j]++;
            }
        }
    }

    res = 0LL;
    two = 1LL;

    for(i=0;i<31;i++)
    {
        cnt[i] = (cnt[i] * (cnt[i] - 1LL)) >> 1LL;
        res += two * cnt[i];
        two <<= 1;
    }

    printf("%lld\n",res);


    return 0;
}
