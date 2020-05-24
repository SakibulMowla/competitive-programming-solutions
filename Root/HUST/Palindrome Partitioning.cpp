#define SZ 1010
#include "stdio.h"
#include "string.h"

int palin[SZ][SZ] , len , dp[SZ];
char arr[SZ];
template <class T> T min(T a,T b) { return a < b ? a : b; }

int solve(int n)
{
    if(n == len) return 0;
    int i,&ans=dp[n];
    if(ans != -1) return ans;
    ans = 1<<28;
    for(i=n;i<len;i++)
        if(palin[n][i])
            ans = min(ans , 1 + solve(i+1));
    return ans;
}

void generate()
{
    int i,j,k;
    for(i=0; i<len; i++) palin[i][i] = 1;
    for(i=0; i<len-1; i++) palin[i][i+1] = arr[i] == arr[i+1];
    for(i=2; i<len; i++)
        for(j=0; j<len; j++)
            if(i+j<len)
                palin[j][i+j] = (palin[j+1][i+j-1] && arr[j] == arr[i+j]);
}

int main()
{
    int t=0,test,i,j;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",arr);
        len = strlen(arr);
        for(i=0;i<=len;i++) dp[i] = -1;
        generate();
        printf("Case %d: %d\n",++t,solve(0));
    }

    return 0;
}
