#include "stdio.h"
#include "string.h"

int arr1[35] , arr2[35];

int main()
{
    int n,tot,i,j,mx,mn;
    while(scanf("%d %d",&n,&tot) == 2)
    {
        mx = mn = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&arr1[i],&arr2[i]);
            mn += arr1[i] , mx += arr2[i];
        }
        if(tot >= mn && tot <= mx)
        {
            for(i=0;i<n;i++)
            {
                while(mn < tot && arr1[i] < arr2[i])
                {
                    mn++;
                    arr1[i]++;
                }
            }
            printf("YES\n");
            for(i=0;i<n;i++)
                printf("%d%c",arr1[i], i==n-1 ? '\n' : ' ');
        }
        else
            printf("NO\n");
    }

    return 0;
}
