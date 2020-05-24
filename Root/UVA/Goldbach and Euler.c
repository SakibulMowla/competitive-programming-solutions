#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool arr[100000010];

void sieve()
{
    int i, j, k;

    arr[0]=arr[1]=1;
    for(i=4;i<100000005;i+=2)
        arr[i]=1;

    k = sqrt(100000005);

    for(i=3;i<k;i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i;j<100000005;j+=i<<1)
                arr[j]=1;
        }
    }

    return;
}

void gold(int n)
{
    if(n == 1)
    {
        printf("%d is not the sum of two primes!\n",n);
        return;
    }

    int i, k;

    if(n&1)
    {
        if(arr[n-2] == 0) printf("%d is the sum of 2 and %d.\n",n,n-2);
        else printf("%d is not the sum of two primes!\n",n);
        return;
    }

    k=0;

    for(i=n/2-1;i>=1;i--)
    {
        if(!arr[i] && !arr[n-i])
        {
            k=1;
            break;
        }
    }
    if(k==0)
        printf("%d is not the sum of two primes!\n",n);
    else if(k==1)
        printf("%d is the sum of %d and %d.\n",n,i,n-i);

    return;
}

int main()
{
    sieve();
    return 0;

    int n;

    while(scanf("%d",&n)==1)
        gold(n);

    return 0;
}
