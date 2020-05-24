#include "stdio.h"
#include "algorithm"
#define SZ 110
using namespace std;
typedef long long ll;

//%I64d
ll arr[SZ];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll n,x,i,k;
    while(scanf("%I64d %I64d",&n,&x) == 2)
    {
        for(i=0;i<n;i++) scanf("%I64d",&arr[i]) , arr[i] *= (n-i);
        sort(arr,arr+n);
        i = k = 0;
        while(i < n && k + arr[i] <= x) k += arr[i] , i++;
        printf("%I64d\n",i);
    }

    return 0;
}
