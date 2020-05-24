#include "stdio.h"

typedef long long ll;

ll notes[]= {10000,5000,2000,1000,500,200,100,50,20,10,5};
ll dp[30000+10];

int main()
{
    ll i,j,d,c,total;

    dp[0] = 1;
    for(i=0; i<11; i++)
    {
        for(j=notes[i]; j<=30000; j++)
            dp[j] = dp[j] + dp[j-notes[i]];
    }

    while(scanf("%lld.%lld",&d,&c) == 2)
    {
        total = (d * 100) + c;
        if(!total) return 0;
        printf("%3lld.%02lld%17lld\n",d,c,dp[total]);
    }

    return 0;
}
