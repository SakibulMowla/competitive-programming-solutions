#include "stdio.h"
#include "string.h"
#include "string"
#include "iostream"

using namespace std;

#define SZ 110
#define SD(n) scanf("%d",&n)
#define SS(n) scanf("%s",n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)

string dp[SZ][SZ];
char arr1[SZ] , arr2[SZ];
int len1,len2;

void LCS()
{
    int i,j;
    FORI(i,1,len1) FORI(j,1,len2)
    {
        if(arr1[i-1] == arr2[j-1]) dp[i][j] = dp[i-1][j-1] + arr1[i-1];
        else if(dp[i-1][j].size() > dp[i][j-1].size()) dp[i][j] = dp[i-1][j];
        else if(dp[i-1][j].size() < dp[i][j-1].size()) dp[i][j] = dp[i][j-1];
        else if(dp[i-1][j] < dp[i][j-1]) dp[i][j] = dp[i-1][j];
        else dp[i][j] = dp[i][j-1];
    }
}

int main()
{
    int t,test;
    t = 0;
    SD(test);
    while(test--)
    {
        SS(arr1) , SS(arr2);
        len1 = strlen(arr1) , len2 = strlen(arr2);
        LCS();
        printf("Case %d: ",++t);
        if(dp[len1][len2].size() == 0) printf(":(");
        else cout << dp[len1][len2];
        printf("\n");
    }

    return 0;
}
