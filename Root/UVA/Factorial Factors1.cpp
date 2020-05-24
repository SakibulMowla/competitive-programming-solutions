#include <stdio.h>
#include <math.h>

int arr[1005],prime[170],factorial[1000010];

void sieve(void)
{
    int i,j,k;
    arr[0]=arr[1]=1;
    prime[0]=2;
    for(i=3;i<sqrt(1005);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<1005;j+=i+i)
                arr[j]=1;
        }
    }
    k=1;
    for(i=3;i<1005;i+=2)
        if(arr[i]==0)
            prime[k++]=i;

    return;
}

int factor(int n)
{
    int i,k;
    k=0;
    for(i=0;prime[i]<=sqrt(n) && n!=1 && i<169;i++)
    {
        while(n%prime[i]==0)
        {
            k++;
            n/=prime[i];
        }
    }
    if(n!=1) k++;

    return k;
}

void num_of_factor(void)
{
    int i;
    for(i=2;i<1000001;i++)
    {
        factorial[i]=factorial[i-1]+factor(i);
    }

    return;
}

int main()
{
    sieve();
    num_of_factor();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",factorial[n]);
    }
    return 0;
}

