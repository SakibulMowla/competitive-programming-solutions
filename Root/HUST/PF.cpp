#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "math.h"
#include "queue"
#include "stack"
#include "algorithm"
#include "iostream"

using namespace std;

#define inf 1<<28
#define SZ 110

int arr[SZ];
vector <int> prime;

void sieve()
{
    int i,j;
    for(i=3;i<sqrt(SZ);i+=2)
        if(arr[i] == 0)
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3;i<SZ;i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

int main()
{
    sieve();
    int t,n,i,j,k,test=0;
    bool blank;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        blank = false;
        printf("Case %d: %d =",++test,n);
        for(i=0;i<prime.size() && prime[i] <= n;i++)
        {
            k = n;
            j = 0;
            while(k >= prime[i])
            {
                j += k / prime[i];
                k /= prime[i];
            }
            if(j != 0)
            {
                if(blank) printf(" *");
                blank = true;
                printf(" %d (%d)",prime[i],j);
            }
        }
        printf("\n");
    }

    return 0;
}
