#include<stdio.h>

int main()
{
    int n;
    while((scanf("%d",&n))==1)
    {
        if(n<0)
            break;
        printf("%d\n",((n*(n+1))/2)+1);
    }
    return 0;
}
