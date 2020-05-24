/*
ID: sakibul1
PROG: milk2
LANG: C++
*/



#include "bits/stdc++.h"

using namespace std;

#define SZ 1000000+10

int dp[SZ];

int main()
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int i, j, k, n, one, zero, strt, end, milk, nomilk;

    while(scanf("%d",&n) == 1)
    {
        strt = 1e6;
        end = 0;
        memset(dp, 0, sizeof(dp));

        for(i=0; i<n; i++)
        {
            scanf("%d %d",&j,&k);
            dp[j]++;
            dp[k]--;
            if(j < strt) strt = j;
            if(k-1 > end) end = k-1;
        }

        zero = one = 0;
        milk = nomilk = 0;

        for(i=strt; i<=end; i++)
        {
            if(dp[i] == 0) zero++, one = 0;
            else one++, zero = 0;

            if(one > milk) milk = one;
            if(zero > nomilk) nomilk = zero;

            dp[i+1] += dp[i];
        }

        printf("%d %d\n",milk,nomilk);
    }

    return 0;
}
