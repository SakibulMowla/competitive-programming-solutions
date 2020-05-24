#include <stdio.h>

void extend_gcd(int a,int b,int &g,int &x,int &y)
{
    if(b==0)
    {
        g=a;x=1;y=0;
    }
    else
    {
        extend_gcd(b,a%b,g,y,x);
        y-=x*(a/b);
    }
    return;
}

int main()
{
    int a,b,g,x,y;
    while(scanf("%d %d",&a,&b) == 2)
    {
        extend_gcd(a,b,g,x,y);
        printf("%d %d %d\n",x,y,g);
    }

    return 0;
}
