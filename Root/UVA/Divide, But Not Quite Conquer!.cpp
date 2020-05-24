#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    long long n,m,j,k,arr[100000];
    while(scanf("%lld %lld",&n,&m) == 2)
    {
        if(n<2 || m<2 || n<m)
        {
            printf("Boring!\n");
            continue;
        }
        k=0;
        while(1)
        {
            if(n==1)
            {
                arr[k]=1;
                for(j=0;j<k;j++)
                    printf("%lld ",arr[j]);
                printf("%lld\n",arr[k]);
                break;
            }
            else if(n%m == 0)
            {
                arr[k]=n;
                k++;
                n=n/m;
            }
            else
            {
                printf("Boring!\n");
                break;
            }
        }
    }
    return 0;
}
