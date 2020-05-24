#include <stdio.h>
#include <math.h>

int prime[500010], arr[5000010], de[5000010], prime_sum[5000010];

void sieve(void)
{
    int i, j, c, k;

    arr[0]=arr[1]=1;

    for(i=4; i<5000010; i+=2)
        arr[i]=1;

    k = sqrt(5000010);

    for(i=3; i<=k; i+=2)
    {
        if(arr[i]==0)
        {
            for(j=i*i; j<5000010; j+=i<<1)
                arr[j]=1;
        }
    }

    prime[0]=2;
    c=1;

    for(i=3; i<5000010; i+=2)
        if(arr[i]==0)
            prime[c++]=i;

    for(i=0; i<c; i++)
        for(j=prime[i]; j<5000010; j+=prime[i])
            prime_sum[j] += prime[i];

    return;
}


int main()
{
    sieve();

    int i, n, m, k;

    for(i=2; i<5000010; i++)
    {
        de[i] = de[i-1];
        if(arr[prime_sum[i]] == 0)
            de[i] += 1;
    }

    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d",&m);
        k = de[m] - de[n-1];
        printf("%d\n",k);
    }

    return 0;
}
