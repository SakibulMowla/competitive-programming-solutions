#include "stdio.h"

#define SZ 40

int N;
int mark[SZ] , dp[SZ][SZ][SZ];

int solve(int indx,int koyta,int cnt)
{
    if(indx == N+1)
    {
        if(!cnt) return 1;
        return 0;
    }
    int &ret = dp[indx][koyta][cnt];
    if(ret != -1) return ret;
    ret = 0;
    ret += solve(indx+1,koyta+1,cnt+1);
    if(cnt>0 && !mark[indx]) ret += solve(indx+1,koyta,cnt-1);
    return ret;
}

int main()
{
    int t,i,j,k,p,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        N = n = 2 * n;
        for(i=0;i<=n;i++)
        {
            mark[i] = 0;
            for(j=0;j<=n;j++) for(p=0;p<=n;p++)
                dp[i][j][p] = -1;
        }
        for(i=0;i<k;i++)
        {
            scanf("%d",&j);
            mark[j] = 1;
        }
        printf("%d\n",solve(1,0,0));
    }

    return 0;
}
