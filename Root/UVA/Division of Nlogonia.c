#include<stdio.h>

int main()
{
    long long int n,x,y,a,b,i;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        scanf("%lld %lld",&x,&y);
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld",&a,&b);
            if(x==a || y==b)
                printf("divisa\n");
            else if(a>x && b>y)
                printf("NE\n");
            else if(a>x && b<y)
                printf("SE\n");
            else if(a<x && b>y)
                printf("NO\n");
            else if(a<x && b<y)
                printf("SO\n");
        }
    }
    return 0;
}
