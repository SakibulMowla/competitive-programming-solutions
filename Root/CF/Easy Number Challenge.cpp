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
    for(i=3; i<sqrt(SZ1); i+=2)
        if(arr[i] == 0)
            for(j=i*i; j<SZ1; j+=i+i)
                arr[j] = 1;
    prime.push_back(2);
    for(i=3; i<SZ1; i+=2)
        if(arr[i] == 0)
            prime.push_back(i);
}

int nod(int n)
{
    int i,j,mul;
    mul = 1;
    for(i=0; i<prime.size() && prime[i] <= n && n!=1; i++)
    {
        j = 1;
        while(n % prime[i] == 0)
        {
//            printf("n = %d prime = %d\n",n,prime[i]);
            j++;
            n /= prime[i];
        }
        mul *= j;
    }
    if(n != 1) mul *= 2;
    return mul;
}

const int mod = 1073741824;

int main()
{
    sieve();
    int i,j,k,a,b,c,ans;
    while(scanf("%d %d %d",&a,&b,&c) == 3)
    {
        ans = 0;
        for(i=1; i<=a; i++) for(j=1; j<=b; j++) for(k=1; k<=c; k++)
                    ans += nod(i*j*k) % mod ;
        printf("%d\n",ans);
    }

    return 0;
}
