#include "stdio.h"
#include "string.h"
#include "stdbool.h"

#define SZ 35

bool flag[SZ][SZ][SZ][SZ];
long long dp[SZ][SZ];

int main()
{
    long long t,i,j,k,n,w,x1,y1,x2,y2;
    char ch;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
            {
                dp[i][j] = 0;
                for(k=0; k<=n; k++)
                    for(w=0; w<=n; w++)
                        flag[i][j][k][w] = true;
            }

        scanf("%lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&w);
        dp[x1][y1] = 1;
        for(i=0; i<w; i++)
        {
            scanf("%lld %lld %c",&j,&k,&ch);
            switch(ch)
            {
            case 'S' :
                flag[j][k][j][k-1] = flag[j][k-1][j][k] = false;
                break;
            case 'W' :
                flag[j][k][j-1][k] = flag[j-1][k][j][k] = false;
                break;
            case 'E' :
                flag[j+1][k][j][k] = flag[j][k][j+1][k] = false;
                break;
            case 'N' :
                flag[j][k+1][j][k] = flag[j][k][j][k+1] = false;
                break;
            }
        }
        for(i=x1; i<=x2; i++)
            for(j=y1; j<=y2; j++)
            {
                if(flag[i][j][i-1][j]) dp[i][j] += dp[i-1][j];
                if(flag[i][j][i][j-1]) dp[i][j] += dp[i][j-1];
            }
        printf("%lld\n",dp[x2][y2]);
    }

    return 0;
}
