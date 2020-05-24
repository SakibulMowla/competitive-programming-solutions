#include<stdio.h>

int f91(int n);
int main()
{
    int i;
    while((scanf("%d",&i))==1)
    {
        if(i==0)
            break;

        printf("f91(%d) = %d\n",i,f91(i));
    }
    return 0;
}

int f91(int n)
{
    if(n>=101)
        return (n-10);
    else if(n<=100)
        return f91(f91(n+11));
}
