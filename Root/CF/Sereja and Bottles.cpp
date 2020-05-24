#include "stdio.h"
#include "string.h"
#define SZ 210

int a[SZ], b[SZ], cnt[SZ];

int main()
{
    int i,j,k,n;

    while(scanf("%d",&n) == 1)
    {
        memset(cnt,0,sizeof(int)*(n+2));
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(j == i) continue;
                if(b[i] == a[j])
                    cnt[j] = 1;
            }
        }
        k = 0;
        for(i=1;i<=n;i++)
            if(cnt[i] == 0)
                k++;
        printf("%d\n",k);
    }

    return 0;
}
