#include "stdio.h"
#include "iostream"

using namespace std;

#define SZ 5010

int chk[SZ][SZ];
int dp[SZ];
char arr[SZ];

bool is_palin(int l, int r)
{
    int &ret = chk[l][r];
    if(ret != -1) return ret;

    if(l == r)
        return ret = 1;
    if(l+1 == r)
        return ret = (arr[l] == arr[r]);
    if(arr[l] == arr[r])
        return ret = is_palin(l+1, r-1);
    return ret = 0;
}


int main()
{
    int t, n, i, j;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",arr);

        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
                chk[i][j] = -1;

        dp[0] = 1;

        for(i=1; i<n; i++)
        {
            dp[i] = n + 5;
            if(is_palin(0, i))
                dp[i] = 1;

            for(j=i; j>0; j--)
                if(is_palin(j, i))
                    dp[i] = min(dp[i], 1 + dp[j-1]);
        }
        printf("%d\n",dp[n-1]);
    }

    return 0;
}
