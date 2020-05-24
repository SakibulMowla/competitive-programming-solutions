#include "stdio.h"
#define SZ 110
template <class T> T max(T a,T b) { return a > b ? a : b; }
int dp[SZ][SZ] , arr[SZ][SZ] , n , k;

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

int solve(int p,int q)
{
    if(dp[p][q] != -1) return dp[p][q];
    int i,j,u,v,ans=0;
    for(i=0;i<4;i++)
        for(j=1;j<=k;j++)
        {
            u = p + x[i] * j;
            v = q + y[i] * j;
//            printf("u = %d v = %d\n",u,v);
            if(u>=0 && v>=0 && u<n && v<n && arr[u][v] > arr[p][q])
                ans = max(ans,solve(u,v));
        }
    ans += arr[p][q];
//    printf("ans = %d k = %d\n",ans,k);
    return dp[p][q] = ans;
}

int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&arr[i][j]) , dp[i][j] = -1;
        printf("%d\n",solve(0,0));
        if(t) printf("\n");
    }

    return 0;
}
