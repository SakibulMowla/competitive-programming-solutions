#include "stdio.h"
#include "string.h"

int main()
{
    int t, r, c, k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&r,&c,&k);
        if((r == 1 && c <= 2) || (c == 1 && r <= 2))
            printf("0\n");
        else if(r == 1 || c == 1)
            printf("%d\n",k);
        else
            printf("%d\n",(k+1)/2);
    }
    return 0;
}
