#include "stdio.h"
#include "string.h"

unsigned long long memo[2000][2000];

unsigned long long nCr(unsigned long long n,unsigned long long r)
{
    if(n == r) return 1;
    if(r == 1) return n;
    if(memo[n][r] != -1) return memo[n][r];
    return memo[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

int main()
{
    unsigned long long n,r;
    memset(memo,-1,sizeof(memo));
    while(scanf("%llu %llu",&n,&r) == 2)
    {
        printf("%llu\n",nCr(n,r));
    }

    return 0;
}
