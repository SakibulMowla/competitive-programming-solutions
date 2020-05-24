#include "stdio.h"
#define SZ 100010

typedef long long ll;

int main()
{
    ll i, j, n, pre, cnt, tot;

    while(scanf("%I64d",&n) == 1)
    {
        pre = 1e11;
        tot = cnt = 0;
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&j);
            if(pre == j) cnt++;
            else
            {
                tot += ( cnt*(cnt+1) )/2;
                cnt = 1;
                pre = j;
            }
        }

        tot +=(cnt*(cnt+1)) / 2;

        printf("%I64d\n", tot);
    }

    return 0;
}
