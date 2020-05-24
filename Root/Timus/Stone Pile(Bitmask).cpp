#include "stdio.h"

int arr[25];

int main()
{
    int i,limit,n,sum,ans;
    while(scanf("%d",&n) == 1)
    {
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        limit = (1<<n);
        ans = 1<<28;
        while(limit--)
        {
            sum = 0;
            for(i=0;i<n;i++)
                if(1<<i & limit)
                    sum += arr[i];
                else sum -= arr[i];
            if(sum >= 0 && sum < ans) ans = sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}
