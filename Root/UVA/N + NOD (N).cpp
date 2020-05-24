#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 1000010
#define SZ1 1010

int arr[SZ1];
vector <int> prime;

void sieve()
{
    int i,j;
    for(i=3; i<sqrt(SZ); i+=2)
        if(arr[i] == 0)
            for(j=i*i; j<SZ1; j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3; i<SZ1; i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

int divisors(int n)
{
    int i,k,mul;
    mul = 1;
    for(i=0; prime[i]<=n && i<prime.size(); i++)
    {
        k = 0;
        while(n%prime[i] == 0)
        {
            k++;
            n /= prime[i];
        }
        if(k) mul *= (k+1);
    }
    if(n != 1) mul *= 2;
    return mul;
}

int dp[SZ];

void solve()
{
    int i,j,pre;
    j = pre = 1;
    dp[1] = 1;
    while(pre < SZ)
    {
        for(i=j+1;i<pre;i++) dp[i] = dp[j];
        dp[pre] = dp[pre-1] + 1;
        j = pre;
        pre = pre + divisors(pre);
    }
    for(i=j;i<SZ;i++) dp[i] = dp[j];
}

int main()
{
    sieve();
    solve();
    int m,n,t,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        printf("Case %d: %d\n",++Case,dp[m]-dp[n-1]);
    }

    return 0;
}
