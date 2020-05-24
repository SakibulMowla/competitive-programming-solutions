#include "stdio.h"

int main()
{
    int n,m;
    while(2 == scanf("%d %d",&n,&m))
        printf("%d\n",(n-1)+n*(m-1));

    return 0;
}
