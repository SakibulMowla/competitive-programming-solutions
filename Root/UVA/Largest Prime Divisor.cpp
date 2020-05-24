#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define SZ 10001000

using namespace std;

bool color[SZ];
vector<long long>prime;
vector<long long>primefactors;
bool isNegative;

void sieve(void)
{
    long long i,j;
    color[0] = color[1] = 1;
    for(i=4;i<SZ;i+=2)
        color[i] = 1;
    for(i=3;i<=sqrt(SZ);i+=2)
    {
        if(color[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                color[j] = 1;
    }
    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(color[i] == 0)
            prime.push_back(i);
    return;
}

bool isPrime(long long n)
{
    if(n<2 || n%2==0)return false;
    for(int i=3;i<=sqrt(n);i+=2)
        if(n%i == 0)
            return false;
    return true;
}

long long lpd(long long n)
{
    long long i,num;
    num = n;
    i = 0;
    primefactors.clear();

    while(prime[i] * prime[i] <= n)
    {
        while(num % prime[i] == 0)
        {
            num /= prime[i];
            primefactors.push_back(prime[i]);
        }
        i++;
    }
    if(num > 1)
        primefactors.push_back(num);

    sort(primefactors.begin(),primefactors.end());

    if(isNegative)
        return primefactors[ primefactors.size()-1 ];
    if(primefactors[0] == primefactors[ primefactors.size() - 1 ])
        return -1;
    return primefactors[primefactors.size() - 1];
}

int main()
{
    sieve();
    long long n;
    while(scanf("%lld",&n)==1 &&n)
    {
        if(n<0)
        {
            n *= -1;
            isNegative = true;
        }
        if(n<4 || (n<SZ && color[n]==0) || isPrime(n))
            printf("-1\n");

        else
            printf("%lld\n",lpd(n));
        isNegative = false;
    }
    return 0;
}
