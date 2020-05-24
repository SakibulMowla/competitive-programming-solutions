#include "stdio.h"
#include "string.h"

const int SZ = 1e5 + 5;

int input[SZ] , ans[SZ];

int main()
{
    int n,k,i,j;
    while(scanf("%d %d",&n,&k) == 2)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",&input[i]);
            if(input[i] == input[i-1])
                i-- , n--;
        }
        for(i=1; i<=n; i++)
        {
            if(input[i-1] == input[i+1]) ans[ input[i] ] += 2;
            else ans[ input[i] ] += 1;
        }
        j = 0;
        for(i=1;i<=k;i++)
        {
            if(ans[i] > ans[j]) j = i;
        }
        printf("%d\n",j);
    }

    return 0;
}
