#include "stdio.h"
#include "iostream"

using namespace std;

#define SZ 1010

int dp[SZ][SZ];
int weight[SZ];
int price[SZ];
int N;

int solve(int indx, int left)
{
    if(indx == N)
        return 0;

    int &ret = dp[indx][left];
    if(ret != -1) return ret;

    ret = solve(indx+1, left);
    if(left-weight[indx] >= 0)
        ret = max(ret, price[indx] + solve(indx+1, left-weight[indx]));

    return ret;
}


int main()
{
    int t, v, i, j;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&N,&v);

        for(i=0;i<N;i++)
            scanf("%d",&price[i]);
        for(i=0;i<N;i++)
            scanf("%d",&weight[i]);

        for(i=0;i<=N;i++)
            for(j=0;j<=v;j++)
                dp[i][j] = -1;

        printf("%d\n",solve(0, v));
    }

    return 0;
}
