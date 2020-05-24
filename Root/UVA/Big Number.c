#include <stdio.h>
#include <math.h>

long arr[10000010];
int main()
{
    long i,k,l,n;
    double sum=0;
    for(i=1; i<=10000000; i++)
    {
        sum+=log10(i);
        arr[i]=ceil(sum);
    }
    arr[0]=arr[1]=1;
    scanf("%ld",&k);
    for(l=0; l<k; l++)
    {
        scanf("%ld",&n);
        printf("%ld\n",arr[n]);
    }

    return 0;
}
