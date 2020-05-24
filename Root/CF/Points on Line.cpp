#include <stdio.h>
#include <string.h>
#include <math.h>

int arr[100010];

int main()
{
    long long n,i,j,d,ans,cnt;
    while(scanf("%I64d %I64d",&n,&d) == 2)
    {
        for(i=1;i<=n;i++)
            scanf("%I64d",&arr[i]);
        ans = 0;
        j = 2;
        for(i=1;i<=n;i++)
        {
            cnt = 0;
            for(;j<=n && arr[j] - arr[i] <= d;j++);
            ans = ans + ( (j-i-1) * (j-i-2) ) / 2;
        }
        printf("%I64d\n",ans);
    }

    return 0;
}
