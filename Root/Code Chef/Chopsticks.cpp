#include "bits/stdc++.h"
using namespace std;

#define SZ 100010

typedef long long ll;
ll arr[SZ];

int main()
{
    ll t, n, d, i, j, k;

    while(scanf("%lld %lld",&n,&d) == 2)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        sort(arr,arr+n);
        k = 0;
        for(i=0;i<n;i++)
        {
            if(i + 1 < n && abs(arr[i]-arr[i+1]) <= d)
            {
                k++;
                i++;
            }
        }
        printf("%lld\n",k);
    }

    return 0;
}
