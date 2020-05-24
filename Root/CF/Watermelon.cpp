#include "stdio.h"

int main()
{
    int n;
    scanf("%d",&n);
    if(n <= 3 || n % 2 == 1) printf("NO");
    else printf("YES");

    return 0;
}
