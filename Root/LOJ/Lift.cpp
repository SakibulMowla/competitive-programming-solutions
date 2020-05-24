#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int lift , pos , ans , t , test;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        ans = 0;
        scanf("%d %d",&pos,&lift);
        ans += abs(pos - lift) * 4;
        ans += 3 + 3 + 5;
        ans += pos * 4;
        ans += 3 + 5;
        printf("Case %d: %d\n",t,ans);
    }

    return 0;
}
