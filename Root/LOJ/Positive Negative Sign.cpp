#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long test=0, t, k, n, m;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        k = (m*m) * (n/(2*m));
        if(n%(2*m))
            k = k - ( (n*(n+1))/2 - ((n-k)*(n-k+1))/2 );
        printf("Case %lld: %lld\n",++test,k);
    }

    return 0;
}
