#include "stdio.h"

int main()
{
    int i,n,res;
    while(scanf("%d",&n) == 1 && n)
    {
        res = 0;
        while(n--)
        {
            scanf("%d",&i);
            res ^= i;
        }
        if(res == 0) printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}
