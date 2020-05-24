#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long arr[10000+10];
int n;
void where_to_put(long long m)
{
    int i,j;
    if(n==1)
    {
        arr[0]=m;
        return;
    }
    for(i=0;i<n;i++)
    {
        if(m<=arr[i])
        {
            for(j=n-1;j>i;j--)
            {
                arr[j]=arr[j-1];
            }
            arr[i]=m;
            break;
        }
        else if(i==n-1)
            arr[i]=m;
    }
    return;
}
int main()
{
    long long m,res;
    n=0;
    while(scanf("%lld",&m)==1)
    {
        n++;
        where_to_put(m);

        if(n%2==1)
            res=arr[n/2];
        else
            res=(arr[n/2]+arr[n/2-1])/2;
        printf("%lld\n",res);
    }
    return 0;
}
