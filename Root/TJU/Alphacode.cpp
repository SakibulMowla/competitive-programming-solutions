#include "stdio.h"
#include "string.h"

#define SZ 5010

typedef long long ll;

ll dp[SZ] , len;
char arr[SZ];

ll solve(ll pos)
{
    ll &ret = dp[pos];
    if(ret != -1) return ret;

    if(pos >= len) return ret = 1;
    if(arr[pos] == '0') return ret = 0;

    ret = solve(pos+1);
    if(pos+1 < len && (arr[pos]-'0')*10+(arr[pos+1]-'0') <= 26) ret += solve(pos+2);

    return ret;
}

int main()
{
//    freopen("1.txt","r",stdin);
    while(scanf("%s",arr) == 1)
    {
        if(arr[0] == '0') break;

        len = strlen(arr);
        memset(dp,-1,sizeof(ll)*(len+2));

        printf("%lld\n",solve(0));
    }

    return 0;
}
