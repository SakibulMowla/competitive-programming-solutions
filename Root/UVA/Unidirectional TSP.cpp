#include <stdio.h>
#include <string.h>
#include <limits.h>

const int inf = INT_MAX;

int R , C , par[102][102];

void print(int r,int c)
{
    if(c == C-1)
    {
        printf("%d",r+1);
        return;
    }
    printf("%d ",r+1);
    print(par[r][c],c+1);
}

int main()
{
    int input[12][110] , dp[12][110] ,i,j,k,r,c,minim,row;
//    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&R,&C) == 2)
    {
        for(i=0; i<R; i++)
            for(j=0; j<C; j++)
            {
                scanf("%d",&input[i][j]);
                dp[i][j] = inf;
                par[i][j] = 0;
            }
        for(r=0; r<R; r++)
            dp[r][C-1] = input[r][C-1];
        for(c=C-2; c>=0; c--)
            for(r=0; r<R; r++)
                for(i=-1; i<=1; i++)
                {
                    row = (i+r+R) % R;
                    k = input[r][c];
                    if(dp[r][c] >= k + dp[row][c+1])
                    {
                        if(dp[r][c] > k + dp[row][c+1] || par[r][c] > row)
                            par[r][c] = row;
                        dp[r][c] = k + dp[row][c+1];
                    }
                }
        minim = 0;
        for(r=0; r<R; r++)
            if(dp[minim][0] > dp[r][0])
                minim = r;
        print(minim , 0);
        printf("\n%d\n",dp[minim][0]);
    }

    return 0;
}
