#include "stdio.h"
#include "algorithm"
#include "iostream"

using namespace std;

#define SZ 32770

typedef long long ll;

ll sum1[SZ];

ll b_search(ll hi, ll lo, ll val)
{
    ll mid, ans = 0;

    while(lo <= hi)
    {
        mid = (hi+lo)>>1;
//        printf("%lld %lld %lldlh\n",lo,hi,mid);
        if(sum1[mid] <= val)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    return ans;
}

int main()
{
    ll arr1[17], arr2[17];
    ll test = 0, t, i, j, k, n, w, len1, len2, lim, ans, sum;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&w);

        for(i=0;i<n/2;i++)
            scanf("%lld",&arr1[i]);

        len1 = i;
        j = 0;

        for(;i<n;i++)
            scanf("%lld",&arr2[j++]);

        len2 = j;

        lim = (1<<len1);
        j = 0;

        while(lim--)
        {
            sum = 0;
            for(i=0;i<len1;i++)
                if(lim&(1<<i))
                    sum += arr1[i];
            sum1[j++] = sum;
        }

        sort(sum1, sum1+j);

        len1 = j;

        lim = (1<<len2);
        ans = 0;

        while(lim--)
        {
            sum = 0;
            for(i=0;i<len2;i++)
                if(lim&(1<<i))
                    sum += arr2[i];

            if(sum <= w)
                ans += b_search(len1-1, 0, w-sum) + 1;
        }

        printf("Case %lld: %lld\n",++test,ans);
    }

    return 0;
}
