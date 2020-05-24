#include "stdio.h"

int main()
{
    int i,j,n,k,a,ans;
    while(scanf("%d",&n) == 1)
    {
        ans = 0;
        while(n--)
        {
            scanf("%d %d",&k,&a);
            if(a == 1) k++;
            for(j=1; j<a; j*=4) k++;
            ans = k > ans ? k : ans;
        }
        printf("%d\n",ans);
    }

    return 0;
}
