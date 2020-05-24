#include <stdio.h>

int joseph(int n)
{
    if(n == 1)
        return 1;
    if(n%2 == 0)
        return 2*joseph(n/2)-1;
    else
        return 2*joseph((n-1)/2)+1;
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
        printf("%d\n",joseph(n));
    return 0;
}
