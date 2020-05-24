#include <stdio.h>

int main()
{
    int n;
    int t=0;
    while(scanf("%d",&n)==1 && n)
    {
        printf("Case %d: %d\n",++t,n/2);
    }
    return 0;
}
