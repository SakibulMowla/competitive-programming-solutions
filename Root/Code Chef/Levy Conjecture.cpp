#include "stdio.h"
#include "math.h"
#include "vector"
#include "iostream"
using namespace std;
#define SZ 10010

int arr[SZ];
vector <int> prime;

void sieve()
{
    int i,j,k;
    arr[0] = arr[1] = 1;
    for(i=4;i<SZ;i+=2)
        arr[i] = 1;
    k = sqrt(SZ) + 1;
    for(i=3;i<k;i+=2)
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
    int t,n,i,j,k,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cnt = 0;
        for(i=0;prime[i]<n;i++)
        {
            k = n - prime[i];
            if(k%2 == 0 && arr[k/2] == 0)
                cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
