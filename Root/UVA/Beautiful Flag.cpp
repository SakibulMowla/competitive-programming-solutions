#include "stdio.h"


int main()
{
    int t, r, test = 0;;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&r);

        printf("Case %d:\n",++test);
        printf("%d %d\n", -(9*r)/4, (3*r)/2 );
        printf("%d %d\n", (11*r)/4, (3*r)/2 );
        printf("%d %d\n", (11*r)/4, -(3*r)/2 );
        printf("%d %d\n", -(9*r)/4, -(3*r)/2 );
    }

    return 0;
}
