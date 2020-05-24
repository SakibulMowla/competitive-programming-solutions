#include "stdio.h"
#include "string.h"
#include "math.h"

#define SZ 110
const int inf = 1<<28;

int c , matrix[SZ][SZ] , dp[SZ][1010] , end[SZ];

int solve(int f,int t)
{
    if(dp[f][t] != -1) return dp[f][t];
    int i,maxim,tmp;
    tmp = maxim = -inf;
    if(t==1)
    {
        for(i=0;i<c;i++)
            if(matrix[f][i] > maxim && end[i]==1)
                maxim = matrix[f][i];
        return dp[f][t] = maxim;
    }
    for(i=0;i<c;i++)
    {
        tmp = solve(i,t-1);
        if(tmp+matrix[f][i] > maxim)
            maxim = tmp+matrix[f][i];
    }
    return dp[f][t] = maxim;
}

int main()
{
    int i,j,s,e,t;
    while(scanf("%d %d %d %d",&c,&s,&e,&t) == 4)
    {
        if(c==0 && s==0 && e==0 && t==0) break;
        memset(end,0,sizeof(end));
        for(i=0;i<SZ;i++)
            for(j=0;j<1010;j++)
                dp[i][j] = -1;
        for(i=0;i<c;i++)
            for(j=0;j<c;j++)
                scanf("%d",&matrix[i][j]);
        for(i=0;i<e;i++)
        {
            scanf("%d",&j);
            end[j-1] = 1;
        }
        printf("%d\n",solve(s-1,t));
    }

    return 0;
}
