#include "stdio.h"
#include "math.h"
#include "iostream"
#include "vector"
#include <ctime>

using namespace std;

#define SZ 10000010

bool arr[SZ];
vector <int> prime;

void sieve()
{
    int i,j;
    for(i=4;i<SZ;i+=2)
        arr[i] = 1;
    arr[0] = arr[1] = 1;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3;i<SZ/2;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

int solve(int n)
{
    int i,j,k;
    k = 0;

    for(i=0;prime[i]<=n/2 && i<prime.size();i++)
        if(arr[ n - prime[i] ] == 0)
            k++;

    return k;
}

int main()
{
    sieve();
    int t,test,n;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",++t,solve(n));
    }

    return 0;
}
