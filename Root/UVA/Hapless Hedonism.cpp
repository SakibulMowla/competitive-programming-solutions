#include <stdio.h>

long long arr[1000001];

int main()
{
    int i,n,m;
    long long k=0;
    for(i=4;i<1000001;i++)
    {
        k+=(i-2)/2;
        arr[i]=k+arr[i-1];
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        printf("%lld\n",arr[m]);
    }
    return 0;
}
