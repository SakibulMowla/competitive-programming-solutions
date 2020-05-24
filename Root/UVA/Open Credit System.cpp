#include <stdio.h>
#include <string.h>
#define inf 1<<30

int main()
{
    int test,i,j,n,maxi,best;
    freopen("1.txt","r",stdin);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        scanf("%d",&j);
        maxi = -inf;
        best = j;
        for(i=2; i<=n; i++)
        {
            scanf("%d",&j);
            if(best-j > maxi)maxi = best - j;
            if(j>best)best=j;
        }
        printf("%d\n",maxi);
    }
    return 0;
}
