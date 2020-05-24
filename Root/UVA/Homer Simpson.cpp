#include "stdio.h"
#include "string.h"
#include "math.h"

#define SZ 10010
#define SD(n) scanf("%d",&n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define max(a,b) a > b ? a : b

int arr[SZ];

int main()
{
    int i,j,n,m,t;
    while(scanf("%d %d %d",&n,&m,&t) == 3)
    {
        memset(arr,0,sizeof(int) * (t+1));
        if(n > m) n^=m^=n^=m;
        arr[n] = arr[m] = 1;
        for(i=n; i<=t; i++)
        {
            if(arr[i])
            {
                if(i + n <= t) arr[i+n] = max(arr[i+n] , arr[i] + 1);
                if(i + m <= t) arr[i+m] = max(arr[i+m] , arr[i] + 1);
            }
        }
        if(arr[t]) printf("%d\n",arr[t]);
        else
        {
            j = 0;
            for(i=t-1; i>=0; i--)
            {
                if(arr[i])
                {
                    j = 1;
                    printf("%d %d\n",arr[i],t-i);
                    break;
                }
            }
            if(!j) printf("0 %d\n",t);
        }
    }

    return 0;
}
