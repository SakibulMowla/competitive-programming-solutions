#include "stdio.h"
#define SZ 22

typedef long long ll;

ll arr[SZ];

int main()
{
    ll i, n, k, sum, tmp;

    while(scanf("%I64d %I64d",&n,&k) == 2)
    {
        sum = 0;
        for(i=0; i<k; i++)
        {
            scanf("%I64d",&tmp);
            sum += tmp;
        }
        if(sum < n) printf("0\n");
        else printf("%I64d\n",sum-n);
    }

    return 0;
}
