#include<stdio.h>

void main(void)
{
    int a1,b1,a2,b2,m;
    while(scanf("%d %d %d %d",&a1,&b1,&a2,&b2)==4)
    {
        if(a1==0 && b1==0 && a2==0 && b2==0)
            break;
        if(a2>a1)
            m=(a2-a1)*60+(b2-b1);

        else if(a1==a2)
        {
            if(b2-b1>=0)
                m=b2-b1;
            else
                m=1440-(b1-b2);
        }
        else if(a2<a1)
            m=(24-(a1-a2))*60+(b2-b1);

        printf("%d\n",m);
    }

    return;
}
