#include "stdio.h"
#include "math.h"
#include "iostream"
#include "algorithm"
using namespace std;
#define ULL unsigned long long
#define SULL(a) scanf("%llu",&a)
#define PULL(a) printf("%llu\n",a)

const unsigned long long mod = 1000000007;

int main()
{
    ULL i,arr[5],t,ans;
    SULL(t);
    while(t--)
    {
        for(i=0; i<3; i++)
            SULL(arr[i]);

        sort(arr,arr+3);
        ans = 1;

        for(i=0; i<3; i++)
            arr[i] = (arr[i]-i) % mod;

        for(i=0;i<3;i++)
            ans *= arr[i] , ans %= mod;

        PULL(ans);
    }

    return 0;
}
