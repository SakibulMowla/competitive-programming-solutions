#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "iostream"
#define SZ 200010
#define slld(n) scanf("%I64d",&n)
using namespace std;
typedef long long ll;

ll arr[SZ] , cnt[SZ];

int main()
{
    ll n,q,i,j,k,sum;
    scanf("%I64d",&n);
    scanf("%I64d",&q);
    for(i=1; i<=n; i++) scanf("%I64d",&arr[i]);
    sort(arr+1,arr+n+1);
    while(q--)
    {
        scanf("%I64d",&j);
        scanf("%I64d",&k);
        cnt[j]++;
        cnt[k+1]--;
    }
    for(i=2; i<=n; i++)
        cnt[i] += cnt[i-1];
    sort(cnt+1,cnt+n+1);
    sum = 0;
    for(i=1; i<=n; i++)
        sum += cnt[i] * arr[i];
    printf("%I64d\n",sum);

    return 0;
}
