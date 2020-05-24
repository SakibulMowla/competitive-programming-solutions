#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define SZ 17

ll arr1[SZ+2], arr2[SZ+2];
ll sum1[(1<<SZ)+2], sum2[(1<<SZ)+2];

ll upp_bound(ll hi, ll val)
{
    ll lo = 0, mid;

    while(lo < hi)
    {
        mid = (lo + hi + 1LL) >> 1LL;

        if(sum2[mid] > val)
            hi = mid -1;
        else
            lo = mid;
    }

    if(sum2[lo] > val) lo--;
    return lo;
}

ll low_bound(ll hi, ll val)
{
    ll lo = 0, mid;

    while(lo < hi)
    {
        mid = (lo + hi) >> 1LL;

        if(sum2[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }

    if(sum2[lo] < val) lo++;
    return lo;
}

int main()
{
    ll n, a, b, i, j, n1, n2, k1, k2, sum;

    scanf("%lld %lld %lld",&n,&a,&b);

    n1 = n / 2;
    n2 = n - n1;

    for(i=0; i<n1; i++)
        scanf("%lld",&arr1[i]);

    for(i=0; i<n2; i++)
        scanf("%lld",&arr2[i]);

    k1 = 1LL<<n1;
    k2 = 1LL<<n2;

    for(i=0; i<k1; i++)
    {
        sum = 0;
        for(j=0; j<n1; j++)
            if(i&(1LL<<j))
                sum += arr1[j];
        sum1[i] = sum;
    }

    for(i=0; i<k2; i++)
    {
        sum = 0;
        for(j=0; j<n2; j++)
            if(i&(1LL<<j))
                sum += arr2[j];
        sum2[i] = sum;
    }
    sum2[i] = 1e15;

    sum = 0;

    sort(sum2, sum2+k2);

//    printf("\n\n");
//
//    for(i=0;i<k2;i++)
//        printf("%lld %lld\n",i,sum2[i]);
//
//    printf("\n\n");
//
//    while(~scanf("%lld",&n))
//    {
//        printf("indx = %lld\n",upp_bound(k2, n));
//    }

    for(i=0; i<k1; i++)
    {
        sum += upp_bound(k2-1, b-sum1[i]) - low_bound(k2-1, a-sum1[i]) + 1;
//        printf("sum1 = %lld lo = %lld up = %lld\n",sum1[i],low_bound(k2-1, a-sum1[i]),upp_bound(k2-1, b-sum1[i]));
    }

    printf("%lld\n",sum);

    return 0;
}
