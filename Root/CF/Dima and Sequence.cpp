#include "stdio.h"
#include "string.h"

//%I64d

long long arr[100];

int main()
{
    long long i,ans,k,n,a;
    while(scanf("%I64d",&n)==1)
    {
        memset(arr,0,sizeof(arr));
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&a);
            k = 0;
            while(a)
            {
                k += a%2;
                a /= 2;
            }
            arr[k]++;
        }
        ans = 0;
        for(i=0;i<100;i++)
            ans += arr[i] * (arr[i] - 1) / 2;
        printf("%I64d\n",ans);
    }

    return 0;
}
