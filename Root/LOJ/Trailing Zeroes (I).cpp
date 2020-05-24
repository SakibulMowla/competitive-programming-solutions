#include "stdio.h"
#include "math.h"
#include "vector"
#include "iostream"

using namespace std;
typedef long long ll;
#define SZ 1000010
bool arr[SZ];
vector <ll> prime;

void sieve()
{
    ll i,j,k;
    prime.push_back(2);
//    k = sqrt(SZ);
    for(i=3; i<SZ; i+=2)
        if(arr[i] == 0)
        {
            prime.push_back(i);
            for(j=i*i; j<SZ; j+=i+i)
                arr[j] = 1;
        }
}

ll nod(ll n)
{
    ll i,k,mul,limit;
    mul = 1;
    limit = sqrt(n);
    for(i=0; i<prime.size() && n!=1 && prime[i]<=limit; i++)
    {
        k=1;
        while(n%prime[i] == 0)
        {
            k++;
            n /= prime[i];
        }
        if(k > 1) limit = sqrt(n);
//        printf("k = %lld\n",k);
        mul *= k;
    }
    if(n != 1) mul *= 2;
//    printf("mul = %lld\n",mul);
    return mul - 1;
}

int main()
{
    sieve();
    ll n,t=0,test;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        printf("Case %lld: %lld\n",++t,nod(n));
    }

    return 0;
}
