#include "stdio.h"
#include "math.h"

int main()
{
    int t,n,m,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        scanf("%d %d",&n,&m);
        while(n>=m)
        {
            ans += n/m;
            n = (n/m) + (n%m);
            if(n == 1) break;
        }
        if(n != 1) printf("cannot do this\n");
        else printf("%d\n",ans);
    }

    return 0;
}
