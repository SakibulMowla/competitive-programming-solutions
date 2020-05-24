#include <stdio.h>
#include <math.h>

long long arr[1000000],alprime[100000];
int main(void)
{
    long long int n,m,i,j,k,c,p,q;
    arr[0]=arr[1]=1;
    for(i=4;i<1000000;i+=2)
        arr[i]=1;
    for(i=3;i<sqrt(1000000);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<1000000;j+=i*2)
                arr[j]=1;
        }
    }
    c=0;
    for(i=4;i<1000000000000;i*=2)
        alprime[c++]=i;
    for(i=3;i<1000000;i+=2)
    {
        if(!arr[i])
        {
            for(j=i*i;j<1000000000000;j*=i)
                alprime[c++]=j;
        }
    }

    scanf("%lld",&n);
    for(k=0;k<n;k++)
    {
        scanf("%lld %lld",&p,&q);
        c=0;
        for(i=0;i<80070;i++)
        {
            if(alprime[i]>=p && alprime[i]<=q)
                c++;
        }
        printf("%lld\n",c);
    }

    return 0;
}
