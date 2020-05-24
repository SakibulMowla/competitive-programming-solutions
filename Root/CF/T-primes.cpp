#include "bits/stdc++.h"

typedef long long ll;


bool isPrime(ll n)
{
    ll i, j, k;

    k = sqrt(n);

    for(i=2;i<=k;i++)
        if(n%i == 0)
            return false;

    return true;
}


int main()
{
    ll n, m, i, j, k;

    while(~scanf("%I64d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&j);
            k = sqrt(j);
            if(j > 3 and k*k == j and isPrime(k))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
