#include "stdio.h"

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    if(n > m) printf("%d %d\n",n-1,m);
    else printf("%d %d\n",m-1,n);
}
