#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

#define SZ 10001

bool arr[SZ];
int ans[SZ];
vector <int> primes;

void sieve()
{
    int i,j;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    primes.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i]==0)
            primes.push_back(i);
}

void generate()
{
    int i,j,sum;
    for(i=0;i<primes.size();i++)
    {
        sum = 0;
        for(j=i;j<primes.size();j++)
        {
            sum += primes[j];
            if(sum >= SZ)
                break;
            ans[sum]++;
        }
    }
}

int main()
{
    sieve();
    generate();
    int n;
    while(scanf("%d",&n) == 1 && n)
        printf("%d\n",ans[n]);
    return 0;
}
