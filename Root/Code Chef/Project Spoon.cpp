#include "bits/stdc++.h"
using namespace std;

#define SZ 70
typedef long long ll;

ll ncr[SZ][SZ];

void process()
{
    ll i, j;

    for(i=0; i<SZ; i++)
    {
        for(j=0; j<=i; j++)
        {
            if(j == 0) ncr[i][j] = 1;
            else if(j == 1) ncr[i][j] = i;
            else ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
        }
    }

    return ;
}


int main()
{
    process();
    ll t, n, i;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);
        for(i=1;; i++)
            if(ncr[i][i/2] >= n)
                break;
        printf("%lld\n",i);
    }

    return 0;
}
