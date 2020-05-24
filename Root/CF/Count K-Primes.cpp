#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
#include "iostream"
using namespace std;
#define SZ 100010

int arr[SZ], cumu[SZ][6];
vector <int> prime;

void sieve()
{
    int i, j, k;
    k = sqrt(SZ);
    for(i=3; i<=k; i+=2)
        if(arr[i] == 0)
            for(j=i*i; j<SZ; j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3; i<SZ; i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

void process()
{
    int i, j, k, n, p;

    k = prime.size();

    for(p=2; p<SZ; p++)
    {
        n = p;
        j = 0;

        for(i=0; i<k && n!=1 && prime[i]*prime[i]<=n; i++)
        {
            if(n % prime[i] == 0)
            {
                while(n % prime[i] == 0)
                    n /= prime[i];
                j++;
            }
        }
        if(n != 1)
            j++;
        if(j <= 5)
            cumu[p][j] = 1;
    }

    for(i=1;i<=5;i++)
        for(j=1;j<SZ;j++)
            cumu[j][i] = cumu[j][i] + cumu[j-1][i];
}

int main()
{
    sieve();
    process();
    int t, a, b, k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&k);
        printf("%d\n",cumu[b][k]-cumu[a-1][k]);
    }
}
