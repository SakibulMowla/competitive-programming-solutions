#include<stdio.h>

int main()
{
    int n;
    while((scanf("%d",&n))==1)
    {
        printf("%d\n",n+(n/2));
    }

    return 0;
}
