#include "stdio.h"
#include "string.h"
#include "iostream"
using namespace std;
#define SZ 100

int arr[SZ][SZ] , dp[SZ][SZ] , n;

int solve(int r,int c)
{
    printf("r = %d c = %d\n",r,c);
    if(c == n) return 0;
    int &ret = dp[r][c];
    if(ret != -1) return ret;
    ret = solve(r,c+1);
    if(r != 0) ret = min(ret , solve(r-1,c));
    if(r < n-1 ) ret = min(ret , solve(r+1,c));
    return ret = ret + arr[r][c];
}

int main()
{
    int i,j,k;
    while(cin >> n)
    {
        for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&arr[i][j]);
        k = 1<<28;
        memset(dp,-1,sizeof dp);
        for(i=0;i<n;i++)
            k = min(k , solve(i,0));
        cout << k << "\n";
    }
    return 0;
}
