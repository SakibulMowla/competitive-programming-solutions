#include <stdio.h>
#include <math.h>

long int arr[1000010],prime[1000010];
int main()
{
    long int c,n,m,i,j,k,l,b,t,s;
    for(i=3;i<=sqrt(1000010);i+=2)
        if(arr[i]==0)
            for(j=i*i;j<1000010;j+=i*2)
                arr[j]=1;
    c=0;
    for(i=3;i<1000010;i+=2)
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

        for(i=0;i<1000010;i++)
        {
            if(prime[i]==b)
            {
                t=i;
                break;
            }
        }
        c=0;
        for(i=t;i>=0;i--)
        {
            for(j=0;j<1000010;j++)
            {
                if(prime[i]+prime[j]==n)
                {
                    b=prime[i];
                    s=prime[j];
                    c++;
                    break;
                }
                if(prime[i]+prime[j]>n)
                    break;
            }
            if(c!=0)
                break;
        }
        if(c!=0)
            printf("%ld = %ld + %ld\n",n,s,b);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}
