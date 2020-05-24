#include <stdio.h>
#include <math.h>

long int arr[1000000];
int main()
{
    long int prime[200000],n,m,i,j,k,c;
    arr[0]=arr[1]=1;
    for(i=3; i<=sqrt(1000000); i+=2)
    {

        if(arr[i]==0)
        {
            for(j=i*i; j<1000000; j+=i*2)
                arr[j]=1;
        }
    }
    c=0;
    prime[c++]=2;
    for(i=3; i<1000000; i+=2)
        if(arr[i]==0)
            prime[c++]=i;

    while(scanf("%ld",&n)==1)
    {
        if(n==0) break;
        k=0;
        for(i=0,m=n; m!=1; i++)
        {
            for(c=0; m%prime[i]==0; c++)
            {
                m/=prime[i];
                if(c==0)
                    k++;
            }
        }
        printf("%ld : %ld\n",n,k);
    }

    return 0;
}
