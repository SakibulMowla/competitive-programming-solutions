#include <stdio.h>
#include <math.h>
#include <vector>

#define SZ 1000010

using namespace std;

bool arr[SZ];
vector <int> prime;

void sieve(void)
{
    int i,j;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;

    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

void factoring(long long n)
{
    long long i,j,k,l,size;
    size = prime.size();
    for(i=0 ; n!=1 && i<size ; i++)
    {
        while(n%prime[i] == 0)
        {
            printf("    %d\n",prime[i]);
            n /= prime[i];
        }
    }
    if(n>1)
        printf("    %lld\n",n);
    printf("\n");
}

int main()
{
    sieve();
    long long n;
    while(scanf("%lld",&n) == 1)
    {
        if(n<0)
            break;
        factoring(n);
    }

    return 0;
}
