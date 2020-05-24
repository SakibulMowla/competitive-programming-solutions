#include "stdio.h"
#include "iostream"
using namespace std;
#define FOR(i,n)for(i=0;i<n;i++)
#define FORI(i,a,n)for(i=a;i<=n;i++)
#define SZ 200
#define getcx getchar_unlocked

int max(int a,int b) { return a > b ? a : b; }
int banana[SZ][SZ] , dp[SZ][SZ];

inline void SD( int &n )//fast input function
{
        n=0;
        int ch=getcx();int sign=1;
        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

        while(  ch >= '0' && ch <= '9' )
                n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
        n=n*sign;
}

int main()
{
    int test,t,n,i,j,k;
    t = 0;
    SD(test);
    while(test--)
    {
        SD(n);
        for(i=0;i<n;i++) for(j=0;j<=i;j++)
        {
            SD(banana[i][j]);
            if(i+j == 0) dp[i][j] = banana[i][j];
            else if(j==0) dp[i][j] = dp[i-1][j] + banana[i][j];
            else dp[i][j] = max(dp[i-1][j] , dp[i-1][j-1]) + banana[i][j];
        }
        k = 1;
        for(i=n;i<2*n-1;i++,k++) for(j=0;j<n-k;j++)
        {
            SD(banana[i][j]);
            dp[i][j] = max(dp[i-1][j] , dp[i-1][j+1]) + banana[i][j];
        }
        printf("Case %d: %d\n",++t,dp[i-1][j-1]);
    }

    return 0;
}
