#include<stdio.h>

int arr[101];
int main(void)
{
    unsigned long long i,j,k,l,n,b;
    while(scanf("%llu",&n)==1)
    {
        if(n==0)
            break;
        b=0;
        for(i=0; i<n; i++)
        {
            scanf("%llu",&j);
            arr[j]++;
            if(j>b)
                b=j;
        }
        l=0;
        for(i=0; i<=b; i++)
        {
            if(arr[i]==0)
                continue;
            else
            {
                for(k=0; k<arr[i]; k++)
                {
                    if(k==0 && l==0)
                        printf("%llu",i);
                    else
                        printf(" %llu",i);
                }
                l++;

            }
        }
        printf("\n");
        for(i=0; i<=100; i++)
            arr[i]=0;
    }
    return 0;
}
