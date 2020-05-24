#include "stdio.h"

#define SZ 110

int dp[SZ][SZ] ,arr[SZ][SZ];

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

int n,k;

int max(int a,int b) { return a > b ? a : b; }

int dfs(int p,int q)
{
    if(dp[p][q] != -1) return dp[p][q];
    int i,j,u,v,ans = 0;
    for(i=1;i<=k;i++)
        for(j=0;j<4;j++)
        {
            u = p + x[j]*i;
            v = q + y[j]*i;
            if(u>=0 && v>=0 && u<n && v<n && arr[u][v] > arr[p][q])
                ans = max(ans,dfs(u,v));
        }
    ans += arr[p][q];
    return dp[p][q] = ans;
}

int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&arr[i][j]) , dp[i][j] = -1;
        printf("%d\n",dfs(0,0));
        if(t) printf("\n");
    }

    return 0;
}
