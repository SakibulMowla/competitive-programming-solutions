#include "bits/stdc++.h"
using namespace std;

#define SZ 100010

typedef long long ll;

ll arr[SZ];


bool valid(ll n, ll mid)
{
    ll i, sum = 0;

    for(i=0; i<n; i++)
    {
        if(arr[i] > mid)
            return false;
        sum += mid - arr[i];
    }
    return sum >= mid;
}


int main()
{
    ll lo, hi, mid, ans, n, i;

    while(~scanf("%I64d",&n))
    {
        for(i=0; i<n; i++)
            scanf("%I64d",&arr[i]);

        lo = 0LL;
        hi = 10000000000LL;

        while(lo <= hi)
        {
            mid = lo - (lo-hi)/2;
            if(valid(n, mid))
            {
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }

        printf("%I64d\n",ans);
    }


    return 0;
}
