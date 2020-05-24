#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
    int i,j,n,num,cur;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cur = 0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&num);
            if(i != j)
                cur |= num;
        }
        printf("%d ",cur);
    }

    return 0;
}
