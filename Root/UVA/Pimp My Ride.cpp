#include "stdio.h"

int Set(int n,int pos) { return n = n | (1<<pos); }
int reset(int n,int pos) { return n = n & ~(1<<pos); }
int check(int n,int pos) { return n & (1<<pos); }

template <class T> T min(T a,T b) { return a < b ? a : b; }

int dp[(1<<14)+2] , cost[16][16] , n;

int solve(int mask)
{
//    printf("mask = %d n = %d\n",mask,n);
    if(mask == (1<<n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];
    int &ret=dp[mask] , tmp ,i ,j;
    ret = 1<<28;
    for(i=0; i<n; i++)
    {
        tmp = cost[i][i];
        for(j=0;j<n;j++)
        {
            if(j == i) continue;
            if(check(mask,j)) tmp += cost[i][j];
        }
        ret = min(ret , tmp+solve(Set(mask,i)));
    }
    return ret;
}

int main()
{
    int t=0,test,i,j,m;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&m);
        n = m;
        for(i=0; i<m; i++)
            for(j=0; j<m; j++)
                scanf("%d",&cost[i][j]);
        j = (1<<m) + 2;
        for(i=0;i<j;i++) dp[i] = -1;
        printf("Case %d: %d\n",++t,solve(0));
    }

    return 0;
}
