#include "bits/stdc++.h"
#define SZ 52

int arr[SZ];

int main()
{
    int i, n, k, need;

    while(~scanf("%d %d",&n,&k))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);

        if(arr[k] == 0)
            need = 1;
        else
            need = arr[k];

        for(i=1;i<=n;i++)
        {
            if(arr[i] < need)
                break;
        }

        printf("%d\n",--i);
    }

    return 0;
}
