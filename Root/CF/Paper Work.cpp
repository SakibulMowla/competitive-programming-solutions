#include "stdio.h"

int arr[200];

int main()
{
    int i,n,m,num,neg,p;
    scanf("%d",&n);
    neg = p = 0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        if(num < 0) neg++;
        arr[p]++;
        if(neg == 3)
        {
            arr[p++]--;
            arr[p] = 1;
            neg = 1;
        }
    }
    p++;
    printf("%d\n%d",p,arr[0]);
    for(i=1;i<p;i++) printf(" %d",arr[i]);
    printf("\n");

    return 0;
}
