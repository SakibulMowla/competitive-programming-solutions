#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 50010

int arr[SZ];
vector <int> prime;

void sieve()
{
    int i,j;
    for(i=3;i<=sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

int Euler_s_totient(int n)
{
    double ans;
    int i;
    ans = n;
    for(i=0;i<prime.size() && n!=1 && prime[i]<=n;i++)
    {
        if(n % prime[i] == 0)
        {
            while(n % prime[i] == 0) n /= prime[i];
            ans *= ( 1 - ( 1 / (double)prime[i] ) );
        }
    }
    if(n != 1) ans *= ( 1 - ( 1 / (double)n ) );
    return (int)ans;
}

int pre[SZ];

int main()
{
    sieve();
    int i;
    pre[1] = 1;
    for(i=2;i<SZ;i++)
        pre[i] = pre[i-1] + Euler_s_totient(i) * 2;
    while(scanf("%d",&i) == 1 && i)
        printf("%d\n",pre[i]);

    return 0;
}
