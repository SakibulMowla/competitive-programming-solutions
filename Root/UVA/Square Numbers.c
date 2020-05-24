#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,i,c,e;
    double d;
    while((scanf("%d %d",&a,&b))==2)
    {
        if(a==0 && b==0)
            break;
        c=0;
        for(i=a;i<=b;i++)
        {
            d=sqrt(i);
            e=sqrt(i);
            if(d==(double)e)
                c++;
        }
        printf("%d\n",c);
    }

    return 0;
}
