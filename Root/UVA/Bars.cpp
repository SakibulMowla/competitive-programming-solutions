#include "stdio.h"

int main()
{
    int i,j,k,n,lim,t,sum;
    int arr[22];
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%d %d",&k,&n);
        for(i=0;i<n;i++) scanf("%d",&arr[i]) , sum += arr[i];
        lim = 1<<n;
        while(lim--)
        {
            j = 0;
            for(i=0;i<n;i++)
                if(1<<i&lim) j += arr[i];
            if(j == k || sum - j == k)
            {
                i = -1;
                break;
            }
        }
        if(i == -1) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
