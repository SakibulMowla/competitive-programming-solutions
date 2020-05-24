#include "stdio.h"

int cumu[110];

int main()
{
    int i,j,n,a,b;
    while(scanf("%d",&n) == 1)
    {
        for(i=2;i<=n;i++)
        {
            scanf("%d",&j);
            cumu[i] = cumu[i-1] + j;
        }
        scanf("%d %d",&a,&b);
        printf("%d\n",cumu[b]-cumu[a]);
    }

    return 0;
}
