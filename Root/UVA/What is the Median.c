#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long arr[10000+10];
int compare (const void * a, const void * b){ return ( *(int*)a - *(int*)b );}
int main()
{
    long long n,res;
    n=0;
    while(scanf("%lld",&arr[n++])==1)
    {
        qsort(arr,n,sizeof(long long int),compare);

        if(n%2==1)
            res=arr[n/2];
        else
            res=(arr[n/2]+arr[n/2-1])/2;
        printf("%lld\n",res);
    }
    return 0;
}
