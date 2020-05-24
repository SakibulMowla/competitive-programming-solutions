#include "bits/stdc++.h"

int main()
{
    int arr[10], i, j, k, f;

    while(scanf("%d",&arr[8]) == 1)
    {
        for(i=7;i>=0;i--)
            scanf("%d",&arr[i]);
        f = 0;
        for(i=8;i>=0;i--)
        {
            if(arr[i])
            {
                if(f)
                {
                    if(arr[i] > 0) printf(" + ");
                    else printf(" - ");
                }
                if(!f)
                {
                    f = 1;
                    if(arr[i] < 0) printf("-");
                }
                if(abs(arr[i]) > 1) printf("%d",abs(arr[i]));
                if(i == 0 && abs(arr[i]) == 1)  printf("%d",abs(arr[i]));
                if(i>1) printf("x^%d",i);
                if(i==1) printf("x");
            }
        }
        printf("\n");
    }

    return 0;
}
