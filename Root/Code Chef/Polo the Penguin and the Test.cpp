#include "bits/stdc++.h"
using namespace std;

#define SZ 102

int dp[SZ][SZ];
int N, W;

int c[SZ], p[SZ], t[SZ];

int solve(int indx, int left)
{
    if(indx == N)
        return 0;

    int &ret = dp[indx][left];
    if(ret != -1)
        return ret;

    ret = 0;

    ret = solve(indx+1, left);
    if(left-t[indx] >= 0)
        ret = max(ret, c[indx]*p[indx] + solve(indx+1, left-t[indx]));

    return ret;
}


int main()
{
    int tt, i;

    scanf("%d",&tt);

    while(tt--)
    {
        scanf("%d %d",&N,&W);

        for(i=0; i<N; i++)
        {
            scanf("%d %d %d",&c[i],&p[i],&t[i]);
        }

        memset(dp, -1, sizeof(dp));

        printf("%d\n",solve(0, W));
    }

    return 0;
}
