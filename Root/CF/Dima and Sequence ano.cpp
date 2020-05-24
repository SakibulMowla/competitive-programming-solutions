#include "stdio.h"
#include "string.h"
#include "math.h"

int arr[34];

int main()
{
    int i,j,n,cnt;
    long long k;

    while(scanf("%d",&n) == 1)
    {
        memset(arr,0,sizeof(arr));
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            cnt = 0;
            while(j)
            {
                cnt += j%2;
                j /= 2;
            }
            arr[cnt]++;
        }
        k = 0;
        for(i=0;i<33;i++)
            k += ( (long long)arr[i]*(long long)(arr[i]-1) ) / 2;
        printf("%I64d\n",k);
    }

    return 0;
}
