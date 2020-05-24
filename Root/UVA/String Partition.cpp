using namespace std;

#include "stdio.h"
#include "string.h"
#include "iostream"

#define MAX 210

typedef long long ll;

char arr[MAX];
ll dp[MAX] , pre[MAX][12] , len;

void summation()
{
    ll i,j,k,sum;

    k = strlen(arr);

    for(i=0; i<k; i++)
    {
        sum = 0LL;
        for(j=0; j<10 && i+j < k; j++)
        {
            sum = sum * 10 + arr[i+j] -'0';
            pre[i][j] = sum;
        }
    }
}

ll solve(ll indx)
{
    if(indx >= len) return 0LL;

    ll &ret = dp[indx];

    if(ret != -1)
        return ret;

    ll i , range = min(indx + 10 , len);

    ret = -1;

    for(i=indx; i<range; i++)
        if(pre[indx][i-indx] < 2147483648LL)
            ret = max(ret , pre[indx][i-indx] + solve(i+1));

    return ret;
}

int main()
{
    ll t,i,k;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%s",arr);

        summation();
        len = k = strlen(arr);

        memset(dp,-1,sizeof(ll)*(k+2));

        printf("%lld\n",solve(0));
    }

    return 0;
}
