#include <stdio.h>
#include <string.h>

int main()
{
    int arr[35] , n , m ,i ,j , p , t;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        memset(arr,0,sizeof(arr));
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&p);
                if(p == 1) arr[j]++;
            }
        }
        ans = 1;
        for(i=1;i<=n;i++)
            if(arr[i] > 1)
                ans *= arr[i];
        printf("%lld\n",ans);
    }

    return 0;
}
