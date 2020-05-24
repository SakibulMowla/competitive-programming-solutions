#include <stdio.h>

int main()
{
    unsigned long long i,k,l,n,sum,arr[25],p;

    arr[0]=1;
    for(i=1;i<21;i++)
        arr[i]=i*arr[i-1];

    scanf("%llu",&l);
    for(k=0;k<l;k++)
    {
        scanf("%llu",&n);
        arr[n];
        sum=arr[n];
        for(i=1;i<=n;i++)
        {
            p=arr[n]/arr[i];
            if(i%2==1)
            p=p*(-1);
            sum+=p;
        }
        printf("%llu/%llu\n",sum,arr[n]);
    }
    return 0;
}
