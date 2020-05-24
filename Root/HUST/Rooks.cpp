#include "stdio.h"
#define SZ 32
typedef long long ll;

ll nCr[SZ][SZ] , fact[SZ];

int main()
{
    ll t=0,test,i,j,k,n;
    fact[0] = 1ll;
    for(i=1; i<SZ; i++)
    {
        fact[i] = i * fact[i-1];
        for(j=0; j<=i; j++)
        {
            if(j == 0) nCr[i][j] = 1ll;
            else if(j == 1) nCr[i][j] = i;
            else if(i == j) nCr[i][j] = 1ll;
            else nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
//            printf("i = %lld j = %lld nCr = %lld\n",i,j,nCr[i][j]);
        }
    }
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&k);
        printf("Case %lld: ",++t);
        if(k>n) printf("0\n");
        else
        {
//            printf("ncr = %lld\n",nCr[i][j]);
            i = nCr[n][k] * nCr[n][k] * fact[k];
            printf("%lld\n",i);
        }
    }

    return 0;
}
