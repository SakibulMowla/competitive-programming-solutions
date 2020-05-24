#include "stdio.h"
#include "iostream"

using namespace std;

#define SZ  1002
#define SZ1 32
#define SZ2 102

int dp[SZ][SZ1];
int price[SZ2];
int weight[SZ2];
int tmp1[SZ];
int tmp2[SZ];


int main()
{
    int t, n, v, i, j, k, l, indx1, indx2, indx;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d",&n,&v,&k);

        for(i=1; i<=n; i++)
            scanf("%d",&price[i]);
        for(i=1; i<=n; i++)
            scanf("%d",&weight[i]);

        for(i=0; i<=v; i++)
            for(j=0; j<=k; j++)
                dp[i][j] = 0;

        for(i=1; i<=n; i++)
        {
            for(j=v; j>=weight[i]; j--)
            {
                for(l=1; l<=k; l++)
                {
                    tmp1[l] = dp[j][l];
                    tmp2[l] = dp[j-weight[i]][l] + price[i];
                }

//                tmp1[l] = tmp2[l] = -1;

                indx = indx1 = indx2 = 1;

                while(indx <= k && indx1 <= k && indx2 <= k)
                {
                    if(tmp1[indx1] > tmp2[indx2])
                        dp[j][indx] = tmp1[indx1++];
                    else
                        dp[j][indx] = tmp2[indx2++];
                    if(dp[j][indx] != dp[j][indx-1])
                        indx++;
                }

                while(indx <= k && indx1 <= k)
                {
                    dp[j][indx] = tmp1[indx1++];
                    if(dp[j][indx] != dp[j][indx-1])
                        indx++;
                }

                while(indx <= k && indx2 <= k)
                {
                    dp[j][indx] = tmp2[indx2++];
                    if(dp[j][indx] != dp[j][indx-1])
                        indx++;
                }
            }
        }

        printf("%d\n",dp[v][k]);
    }

    return 0;
}
