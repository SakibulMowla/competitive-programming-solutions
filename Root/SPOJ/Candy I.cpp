#include "stdio.h"

int arr[100000];

int main()
{
    int n,m,i,j,k;
    while(scanf("%d",&n) == 1 && n!= -1)
    {
        j = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            j += arr[i];
        }
        if((j % n) != 0)
        {
            printf("-1\n");
            continue;
        }
        m = 0;
        k = j / n;
        for(i=0;i<n;i++)
            if(arr[i] > k)
                m += arr[i] - k;
        printf("%d\n",m);
    }

    return 0;
}
