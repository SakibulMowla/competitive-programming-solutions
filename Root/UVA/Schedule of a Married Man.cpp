#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int a1,a2,b1,b2,c1,c2,d1,d2,test,t=0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d:%d %d:%d",&a1,&a2,&b1,&b2);
        a1 = (a1*60) + a2;
        b1 = (b1*60) + b2;
        scanf("%d:%d %d:%d",&c1,&c2,&d1,&d2);
        c1 = (c1*60) + c2;
        d1 = (d1*60) + d2;
        if(d1<a1 || b1<c1)
            printf("Case %d: Hits Meeting\n",++t);
        else
            printf("Case %d: Mrs Meeting\n",++t);
    }

    return 0;
}
