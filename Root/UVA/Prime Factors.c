#include <stdio.h>
#include <math.h>

int arr[46342],prime[4792],flag;
void sieve(void)
{
    int i,j,k;
    arr[0]=arr[1]=1;
    prime[0]=2;
    for(i=4;i<46342;i+=2)
        arr[i]=1;
    for(i=3;i<sqrt(46342);i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<46342;j+=i+i)
                arr[j]=1;
        }
    }
    k=1;
    for(i=3;i<46342;i+=2)
        if(arr[i]==0)
            prime[k++]=i;

    return;
}

void factor(long n)
{
    int i;
    for(i=0;prime[i]<=sqrt(n) && n!=1 && i<4792;i++)
    {
        while(n%prime[i]==0)
        {
            if(flag==0)
            {
                printf(" %d",prime[i]);
                flag=1;
            }
            else
            {
                printf(" x %d",prime[i]);
            }
            n/=prime[i];
        }
    }
    if(n!=1)
    {
        if(flag==0)
            {
                printf(" %d",n);
                flag=1;
            }
            else
            {
                printf(" x %d",n);
            }
    }
    printf("\n");
    return;
}
int main()
{
    sieve();
    long n;
    while(scanf("%ld",&n)==1 && n)
    {
        flag=0;
        if(n<0)
        {
            printf("%ld = -1",n);
            flag=1;
            n*=-1;
        }
        else
        {
            printf("%ld =",n);
        }
        factor(n);
    }

    return 0;
}
