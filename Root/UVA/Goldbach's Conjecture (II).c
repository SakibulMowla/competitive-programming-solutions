#include <stdio.h>
#include <math.h>

int main()
{
    long int arr[40000],prime[40000],c,n,i,j,t,b;
    for(i=3;i<=sqrt(40000);i+=2)
        if(arr[i]==0)
            for(j=i*i;j<40000;j+=i*2)
                arr[j]=1;
    c=1;
    prime[0]=2;
    for(i=3;i<40000;i+=2)
    {
        if(arr[i]==0)
            prime[c++]=i;
    }

    while(scanf("%ld",&n)==1)
    {
        if(n==0) break;
        for(i=n-1;i>2;i-=2)
        {
            if(arr[i]==0)
            {
                b=i;
                break;
            }
        }

        for(i=0;i<40000;i++)
        {
            if(prime[i]==b)
            {
                t=i;
                break;
            }
        }
        c=0;
        for(i=t;i>=0 && prime[i] >= n/2;i--)
        {
            for(j=0;j<40000;j++)
            {
                if(prime[i]+prime[j]==n)
                {
                    c++;
                    break;
                }
                if(prime[i]+prime[j]>n)
                    break;
            }
        }
        printf("%ld\n",c);
    }

    return 0;
}

