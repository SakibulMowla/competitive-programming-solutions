#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define SZ 100000000

int arr[SZ/32 + 2];

bool check(int n,int pos){return (bool)(n & (1<<pos));}
int set(int n,int pos){ return n = n | (1<<pos); }

void sieve()
{
    freopen("Primes.txt","w",stdout);
    int i,j,k=1;
    printf("2\n");
    for(i=3; i<=sqrt(SZ); i+=2)
        if(check(arr[i/32],i%32) == 0)
        {
            k++;
            if(k % 100 == 1)
                printf("%d\n",i);
            for(j=i*i; j<SZ; j+=i+i)
                arr[j/32] = set(arr[j/32] , j%32);
        }

    for(i=10001; i<SZ; i+=2)
        if(check(arr[i/32],i%32) == 0)
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
