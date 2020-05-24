#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define SZ 100000000

bool arr[SZ];

void sieve()
{
    freopen("Primes.txt","w",stdout);
    int i,j,k;
    for(i=3;i<=sqrt(SZ);i+=2)
        if(arr[i]==0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    printf("2\n");
    k = 1;
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
        {
            k++;
            if(k % 100 == 1)
                printf("%d\n",i);
        }
}

int main()
{
    sieve();
    return 0;
}
