#include <stdio.h>

long long arr[1000001];

int main()
{
    int i,n,m;
    long long k=1;
    for(i=4;i<1000001;i+=2,k++)
    {
        arr[i]=arr[i-1]+k*k;
        arr[i+1]=arr[i]+k*k+k;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        printf("%lld\n",arr[m]);
    }
    return 0;
}
