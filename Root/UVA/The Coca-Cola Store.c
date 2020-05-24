#include<stdio.h>

int main()
{
    int i;
    while((scanf("%d",&i))==1)
    {
        if(i==0)
            break;
        printf("%d\n",i/2);
    }
    return 0;
}
