#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;
#define SZ 40000
bool arr[SZ];
vector <int> primes;
void sieve()
{
    int i,j;
    arr[0] = arr[1] = 1;
    for(i=4; i<SZ; i+=2)
        arr[i] = 1;
    for(i=3; i<sqrt(SZ); i+=2)
        if(arr[i] == 0)
            for(j=i*i; j<SZ; j+=i+i)
                arr[j] = 1;

    primes.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            primes.push_back(i);
}

int main()
{
    sieve();
    int i,j,n,m,t,test,flag;
    scanf("%d",&test);
    for(t=0; t<test; t++)
    {
        scanf("%d %d",&n,&m);
        for(i=n; i<m && i<SZ; i++)
        {
            if(arr[i] == 0)
                printf("%d\n",i);
        }
        for(i=min(SZ,m);i<=m;i++)
        {
            j = 0;
            flag = 0;
            while(primes[j] <= sqrt(i))
            {
                if(i%primes[j] == 0)
                {
                    flag = 1;
                    break;
                }
                j++;
                if(primes[j]>=37000)
                    break;
            }
            if(flag == 0)
                printf("%d\n",i);
        }
        if(t<test-1)
            printf("\n");
    }
    return 0;
}
