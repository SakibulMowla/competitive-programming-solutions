#include "stdio.h"
#include "string.h"

int main()
{
    int n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        if(n >= m) printf("MMM BRAINS\n");
        else printf("NO BRAINS\n");
    }

    return 0;
}
