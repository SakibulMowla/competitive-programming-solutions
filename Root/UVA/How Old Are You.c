#include<stdio.h>

int main()
{
    int n,i,a,b,c,a1,b1,c1,d;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d/%d/%d",&a,&b,&c);
        scanf("%d/%d/%d",&a1,&b1,&c1);

        if((c-c1<0 )|| (c-c1 == 0 && b-b1 < 0) || (c-c1 == 0 && b-b1 == 0 && a-a1 <0))
        {
            printf("Case #%d: Invalid birth date\n",i);
            continue;
        }

        else if( b-b1< 0)
            d=c-c1-1;
        else if( b-b1== 0 && a-a1 < 0)
            d=c-c1-1;
        else if( b-b1 >= 0 )
            d=c-c1;

        if(d<=130)
            printf("Case #%d: %d\n",i,d);
        else
            printf("Case #%d: Check birth date\n",i);
    }

    return 0;
}
