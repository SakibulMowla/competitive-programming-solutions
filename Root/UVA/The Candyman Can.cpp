#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "iostream"

using namespace std;

int arr[40] , N , sum;
int dp[645][645][35];

int solve(int a,int b,int n)
{
    int &ret = dp[a][b][n];
    if(n == N)
    {
        int c = sum - (a + b);
        return ret = max(a,max(b,c)) - min(a,min(b,c));
    }
    if(ret != -1) return ret;
    return ret = min(solve(a+arr[n],b,n+1) , min(solve(a,b+arr[n],n+1), solve(a,b,n+1) ) );
}

int main()
{
//    freopen("1.txt","r",stdin);
//    freopen("2.txt","w",stdout);

    int t,i,j,k,n,test=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        N = n;
        sum = 0;
//        memset(dp,-1,sizeof(dp));
        for(i=0; i<n; i++) scanf("%d",&arr[i]) , sum += arr[i];
        for(i=0; i<=sum; i++) for(j=0; j<=sum; j++) for(k=0; k<=n; k++) dp[i][j][k] = -1;
        printf("Case %d: %d\n",++test,solve(0,0,0));
    }

    return 0;
}
