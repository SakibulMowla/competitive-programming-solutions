#include "stdio.h"
#include "string.h"
#include "math.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 100000

int arr[SZ];
vector <int> prime;

void sieve()
{
    int i,j,k;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(k=3;k<SZ;k+=2)
        if(arr[k] == 0)
            prime.push_back(k);
}

int factor(int num)
{
    int i,k,fac;
    fac = 1;
    for(i=0;prime[i]<=sqrt(num);i++)
    {
        if(num % prime[i] == 0)
        {
            k = 1;
            while(num % prime[i] == 0)
            {
                k++;
                num /= prime[i];
            }
            fac *= k;
        }
    }

    if(num != 1) fac *= 2;
    return fac;
}


int main()
{
    sieve();
    int i,fac,num;
    i = 0;
    while(++i)
    {
        num = (i*(i+1)) / 2;
        if(num > 500)
        {
            if(i%2 == 0) fac = factor(i/2) * factor(i+1);
            else fac = factor(i) * factor((i+1)/2);
            if(fac > 500) {printf("num = %d  fac = %d\n",num,fac);break;}
        }
    }

    return 0;
}
